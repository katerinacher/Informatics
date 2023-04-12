#include <iostream>

struct BinaryTree {
	int value;
	BinaryTree* left;
	BinaryTree* right;
};

int SumOfDigit(int num) {
	if (num == 0) {
		return 0;
	} else {
		return (num % 10) + SumOfDigit(num / 10);
	}
}

void AddBinaryTree(BinaryTree** MyTree, BinaryTree* TreeElement) {
	BinaryTree* current;
	current = *MyTree;
	if (current == NULL) {
		*MyTree = TreeElement;
	} else {
		if (SumOfDigit(TreeElement->value) < SumOfDigit(current->value)) {
			AddBinaryTree(&current->left, TreeElement);
		} else {
			AddBinaryTree(&current->right, TreeElement);
		}
	}
}

void PrintTreeHorizont(BinaryTree* MyTree, int level) {
	if (MyTree != NULL) {
		PrintTreeHorizont(MyTree->right, level + 1);
		for (int i = 0; i < level; i++) {
			std::cout << "       ";
		}
		std::cout << MyTree->value << "(" << SumOfDigit(MyTree->value) << ") " << "<" << std::endl;
		PrintTreeHorizont(MyTree->left, level + 1);
	}
}

void PrintTreeSim(BinaryTree* MyTree) {
	if (MyTree != NULL) {
		PrintTreeSim(MyTree->left);
		std::cout << MyTree->value << "(" << SumOfDigit(MyTree->value) << ") ";
		PrintTreeSim(MyTree->right);
	}
}

void PrintTreeDirect(BinaryTree* MyTree) {
	if (MyTree != NULL) {
		std::cout << MyTree->value << "(" << SumOfDigit(MyTree->value) << ") ";
		PrintTreeDirect(MyTree->left);
		PrintTreeDirect(MyTree->right);
	}
}

void PrintTreeReverse(BinaryTree* MyTree) {
	if (MyTree != NULL) {
		PrintTreeReverse(MyTree->left);
		PrintTreeReverse(MyTree->right);
		std::cout << MyTree->value << "(" << SumOfDigit(MyTree->value) << ") ";
	}
}

void PrintTree(BinaryTree* MyTree) {
	printf("\nПечать бинарного дерева поиска при симметричном обходе:\n\n");
	PrintTreeSim(MyTree);
	printf("\n");
	printf("\nПечать бинарного дерева поиска при прямом обходе:\n\n");
	PrintTreeDirect(MyTree);
	printf("\n");
	printf("\nПечать бинарного дерева поиска при обратном обходе:\n\n");
	PrintTreeReverse(MyTree);
	printf("\n");
	printf("\nПечать бинарного дерева поиска горизонтально:\n\n");
	PrintTreeHorizont(MyTree, 0);
	printf("\n");
}

int SizeofBinaryTree(BinaryTree* MyTree) { //рекурсивная функция 
	if (MyTree == NULL) {
		return 0;
	} else {
		return (SizeofBinaryTree(MyTree->left) + 1 + SizeofBinaryTree(MyTree->right));
	}
}

int DepthTree(BinaryTree* MyTree) { // глубина дерева
	int h1 = 0, h2 = 0;
	if (MyTree == NULL) return 0;
	if (MyTree->left) {
		h1 = DepthTree(MyTree->left);
	}
	if (MyTree->right) {
		h2 = DepthTree(MyTree->right);
	}
	if (h1 > h2) {
		return (h1 + 1);
	} else {
		return (h2 + 1);
	}
}

void DeleteNode(BinaryTree** TreeElement) {
	if ((*TreeElement)->left == NULL) {
		(*TreeElement) = ((*TreeElement)->right);
	} else {
		if ((*TreeElement)->right == NULL) {
			(*TreeElement) = ((*TreeElement)->left);
		} else {
			BinaryTree* tmp = (*TreeElement)->left;
			if (tmp->right == NULL) {
				(*TreeElement)->left = tmp->left;
				(*TreeElement)->value = tmp->value;
			} else {
				while (tmp->right->right != NULL) {
					tmp = tmp->right;
				}
				(*TreeElement)->value = tmp->right->value;
				tmp->right = tmp->right->left;
			}
		}
	}
}

bool check(BinaryTree* TreeElement) {
	if (TreeElement != NULL) {
		if ((TreeElement->value) % 2 == 0) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

int CountEvenValue(BinaryTree* TreeElement) {
	if (TreeElement == NULL) {
		return 0;
	} else {
		return ((TreeElement->value) % 2 == 0) + CountEvenValue(TreeElement->left) + CountEvenValue(TreeElement->right);
	}
}

void DeleteEvenValue(BinaryTree** TreeElement) {
	if (TreeElement != NULL) {
		while (check(*TreeElement)) {
			printf("%d  ", **TreeElement);
			DeleteNode(TreeElement);
		}
		if ((*TreeElement) != NULL) {
			DeleteEvenValue(&((*TreeElement)->left));
			DeleteEvenValue(&((*TreeElement)->right));
		}
	}
}

void AddTop(BinaryTree** current, int top_to_add) {
	if (*current != NULL) {
		if (SumOfDigit(top_to_add) < SumOfDigit((*current)->value)) {
			AddTop(&(*current)->left, top_to_add);
		} 
		else if (SumOfDigit(top_to_add) > SumOfDigit((*current)->value)) {
			AddTop(&(*current)->right, top_to_add);
		}
	} else {
		*current = new BinaryTree;
		(*current)->value = top_to_add;
		(*current)->left = NULL;
		(*current)->right = NULL;
	}
}

void Parametrs(BinaryTree* MyTree, int size, int depth) {
	printf("\nГлубина дерева = %3d", DepthTree(MyTree));
	printf("\nКоличество вершин в дереве = %3d\n", SizeofBinaryTree(MyTree));
}

int main() {
	setlocale(0, "rus");
	BinaryTree* MyTree = NULL; 
	BinaryTree* TreeElement;
	char next_number[10];
	int SizeofBinaryTree = 0;
	int Depth = 0;

	printf("Введите число или ENTER для завершения ввода:\n");

	while (gets_s(next_number), strlen(next_number) != 0) {
		TreeElement = new BinaryTree;
		TreeElement->value = atoi(next_number);
		TreeElement->left = NULL;
		TreeElement->right = NULL; 
		AddBinaryTree(&MyTree, TreeElement);
	}

	PrintTree(MyTree);
	Parametrs(MyTree, SizeofBinaryTree, Depth);

	int Counter = CountEvenValue(MyTree);

	if (Counter != 0) {
		printf("\nКоличество чётных чисел: %d\n", Counter);
		printf("Эти числа: ");
		DeleteEvenValue(&MyTree);
		printf("\n");
	} else {
		printf("\nЧётных чисел нет\n");
	}

	printf("\n--------------После удаления чётных чисел--------------\n");
	PrintTree(MyTree);
	Parametrs(MyTree, SizeofBinaryTree, Depth);

	printf("\nВведите вершину, которую хотите добавить:\n");
	int top_to_add;
	scanf_s("%d", &top_to_add);
	AddTop(&MyTree, top_to_add);

	PrintTree(MyTree);
	Parametrs(MyTree, SizeofBinaryTree, Depth);
	return 0;
}