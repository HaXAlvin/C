#include<stdio.h>
int main() {
	char record=0b11111111,change;
	int i,pass[8];
	change=0b00000010;
	record^=change;                                //�ƥ�s���@ 11111111��00000010��xor  �ܦ�11111101,�]���p���j�@�U�����Q��
	change=0b11111011;
	record&=change;                                //�ƥ�s���G 11111101��11111011 ��and �ܦ�11111001 �p���j�G�W�ױK�X��57�� �Q��F
	change=0b00000100;
	record|=change;                                //�ƥ�s���T 11111001��00000100 ��or �ܦ�11111101 �p���j�G�W�D���[��60��
	change=0b11101111;
	record&=change;                                //�ƥ�s���| 11111101��11101111 ��and �ܦ�11101101 �p���j�T�W 50��
	change=0b10111111;                             
	record&=change;                                //�ƥ�s���� 11101101��10111111 ��and �ܦ�10101101  �p���j�|�W�Q��
	for(i=0;i<8;i++){
		change=((record>>i)&0b00000001);
		pass[i]=change;
	}
	printf("�j�@�W:%d\n",pass[0]);
	printf("�j�@�U:%d\n",pass[1]);
	printf("�j�G�W:%d\n",pass[2]);
	printf("�j�G�U:%d\n",pass[3]);
	printf("�j�T�W:%d\n",pass[4]);
	printf("�j�T�U:%d\n",pass[5]);
	printf("�j�|�W:%d\n",pass[6]);
	printf("�j�|�U:%d\n",pass[7]);
	return 0;
}
