#include <stdio.h>
#include <stdlib.h>
int main(){
	char passornot = 0b11111111;
	int happening1 = 0b11111101, happening2 = 0b11111011, happening3 = 0b11111101, happening4 = 0b11101111, happening5 = 0b10111111; //�ƥ�y�����v�T �|�L�g1 �Ϥ��g0
	//1. �b�j�@�U�ɡA�p���]���L�n��¼�F�Ӧh�`�ҡA�������F58���A�Q���F
	int changing1 = passornot & happening1;
	//2. �b�j�G�W�ɡA�פF�K�X�ǡA���]���n��ܦh�ƾǡA�@������A���F57���A�Q��
	int changing2 = changing1 & happening2;
	//3. �b�j�G�W���Ǵ����A�]��K�X�ǦѮv���줽�Ǹ�L�D���A�Ѯv���L�[��60��
	int changing3 = changing2 | happening3;
	//4. �b�j�T�W�ɡA�]���b�^��Ҥ@����ı�A�������F50���A�Q���F
	int changing4 = changing3 & happening4;
	//5. �b�j�|�W�ɡA�פF�`�׾ǲߡA���ǲߪ��p���ΡA�����u���F40���A�Q��F
	int finalchanging = changing4 & happening5;
	int solo1 = 0b00000001 , solo2 = 0b00000010 , solo3 = 0b00000100 , solo4 = 0b00001000 , solo5 = 0b00010000 , solo6 = 0b00100000 , solo7 = 0b01000000 , solo8 = 0b10000000;
	//�C�ӳ椸�ӧO�P�_�O�_��pass 
	if((solo1&finalchanging)>0){
		printf("�j�@�W : 1\n");
	}else{
		printf("�j�@�W : 0\n");
	}
	if((solo2&finalchanging)>0){
		printf("�j�@�U : 1\n");
	}else{
		printf("�j�@�U : 0\n");
	}
	if((solo3&finalchanging)>0){
		printf("�j�G�W : 1\n");
	}else{
		printf("�j�G�W : 0\n");
	}
	if((solo4&finalchanging)>0){
		printf("�j�G�U : 1\n");
	}else{
		printf("�j�G�U : 0\n");
	}
	if((solo5&finalchanging)>0){
		printf("�j�T�W : 1\n");
	}else{
		printf("�j�T�W : 0\n");
	}
	if((solo6&finalchanging)>0){
		printf("�j�T�U : 1\n");
	}else{
		printf("�j�T�U : 0\n");
	}if((solo7&finalchanging)>0){
		printf("�j�|�W : 1\n");
	}else{
		printf("�j�|�W : 0\n");
	}if((solo8&finalchanging)>0){
		printf("�j�|�U : 1\n");
	}else{
		printf("�j�|�U : 0\n");
	}	
    return 0;
}
