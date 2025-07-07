#include <stdio.h>
using namespace std;

typedef struct node{
	char data;
	node *kiri;
	node *kanan;
};

node *akar=NULL;
addNode(node **akar, char isi){
	if((*akar)==NULL){
		node *baru;
		baru = new node;
		baru -> data = isi;
		baru -> kiri = NULL;
		baru -> kanan = NULL;
		(*akar)=baru;
	}
}

preOrder(node *akar){
	if (akar !=NULL){
		printf("%c", akar -> data);
		preOrder(akar -> kiri);
		preOrder(akar -> kanan);
	}
}

inOrder(node *akar){
	if(akar !=NULL){
		inOrder(akar -> kiri);
		printf("%c", akar -> data);
		inOrder(akar -> kanan);
	}
}

int main(){
	char abjad;
	printf("\n\n\tPosusu Awal Tree;\n\n");
	printf("\t	 A\n\t	/\\\n\t	B C\n\t	/\n\t\	D\n\t	\\\n\t	E\n\n");
	addNode(&akar, abjad='A');
	addNode(&akar -> kiri, abjad='B');
	addNode(&akar -> kanan, abjad='C');
	addNode(&akar -> kiri -> kiri, abjad='D');
	addNode(&akar -> kiri -> kiri -> kiri, abjad='E');
	printf("Tampilkan Preorder : ");
	preOrder(akar);
	printf("\nTampilkan InOrder");
	inOrder(akar);
}
