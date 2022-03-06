#include <stdio.h>
#include <stdlib.h>

/*
�ƾڭ���G
�ݩʡGF=���BW=���BG=�g�BA=���C���i��JF�BW�BG�BA�Bf�Bw�Bg�Ba�H�~���^��r���C
��q 40~50�����
���� 15~20�����
���m 5~10�����
3���`�M�b65~70����
�����ˮ`�������G(int)(����������O * �۫g���v * �ݦ孿�v - �Q�����訾�m�O)
    �ݩʬ۫g���v�G
        �ݩ����YW>F>A>G>W
        �Y���۫g���Y�G�u�ժ�1.2���A�H�ժ�0.8��
        �Y����L�۫g�h�����O�U��1.0��
    �ݦ孿�v�G
        �������q�p��쥻��50%�ɴݦ孿�v��1.2��
*/
/*
�Ѧ�https://hackmd.io/@K-54OPo-RMyCWp-fBFE48Q/SkTwAtktB#%E7%AC%AC5%E9%80%B1
�s�W����G�ݩʧP�_�覡�Bcorrect_flag
*/

void EditNewChar(); //�禡�G�s�W����
void PrintCharData(); //�禡�G��ܨ����T
void SelectAndBattle(); //�禡�G�ܥ����A���۶iBattling�԰��禡
void Battling(); //�禡�G�԰�

int n = 3; //�Ω�switch(star_ans)case2��ܨ����ơC�p���s�W����Acase1����n�אּ4
int *n_Addr = &n; //����ƶq(n)���СA�T�O�b�U��ܶ����T�ǻ�
int correct; //flag

char char_name[4][21] = {"Ĩۣ", "��ۣ", "���jۣ"}; //����1�GĨۣ�C����2�G��ۣ�C����3�G���jۣ�C�p�G���A����4

char type[4] = {'G', 'W', 'F'}; //�̧Ǩ���1~3�ݩʡA�w�d�i�s�W����4�ݩ�
int hp[4] = {40, 50, 40}; //�̧Ǩ���1~3��q�A�w�d�i�s�W����4��q
int atk[4] = {20, 15, 15}; //�̧Ǩ���1~3�����A�w�d�i�s�W����4����
int def[4] = {5, 5, 10}; //�̧Ǩ���1~3���m�A�w�d�i�s�W����4���m
int char4_sum; //����4��O�ƭ��`�M
double power; //����j�׹w��

//���𨤦�st
int st_char; //���𨤦⸹
int st_type; //�ݩ�
int st_hp; //��q
int st_half_hp; //�b��
int st_atk; //����
int st_def; //���m
//��𨤦�nd
int nd_char; //��𨤦⸹
int nd_type; //�ݩ�
int nd_hp; //��q
int nd_half_hp; //�b��
int nd_atk; //����
int nd_def; //���m

int first_sum_atk; //��������褧�����q
int second_sum_atk; //��������褧�����q
double first_type_atk; //��������褧�ݩʬ۫g���v
double second_type_atk; //��������褧�ݩʬ۫g���v

int star_game = 1; //�C���}�lflag

int main(){
    while (star_game != 0){
        int star_ans; //�����l�ﶵ�ܼ�
        printf("1.�s�W�έק�s�W����\n"); //case�s�W�έק﨤��4
        printf("2.��ܩҦ�������\n"); //case2��ܨ�����
        printf("3.�԰�\n"); //case3�i�J�԰�
        printf("0.�����C��\n"); //case0�C������flag=0
        printf("�п��:");
        scanf("%d", &star_ans);
        printf("\n");

        switch (star_ans){
            case 1:
                EditNewChar();
                break;
            case 2:
                PrintCharData();
                break;
            case 3:
                SelectAndBattle();
                break;
            case 0:
                printf("�����C��");
                star_game = 0;
        }
    }
    return 0;
}

void EditNewChar(){  //�禡�G�s�W���� 
    do {
        correct = 1; //��l��flag
        printf("�s�W����\n");
        printf("����W�١G");
        scanf("%*c%s", char_name[3]); //��J����W��
        printf("�ݩʡG");
        scanf("%*c%c", &type[3]); //��J�ݩ�
        printf("��q�G");
        scanf("%d", &hp[3]); //��J��q
        printf("�����G");
        scanf("%d", &atk[3]); //��J����
        printf("���m�G");
        scanf("%d", &def[3]); //��J���m
    if (type[3]!='F' && type[3]!='W' && type[3]!='A' && type[3]!= 'G' && type[3]!= 'f' && type[3]!= 'w' && type[3]!= 'a'  && type[3]!= 'g'){
        printf("���~�G�L���ݩ�\n");
        correct = 0;
    }
    else if (type[3] >= 'a'){  //�p�G��J�O�p�g�A��s���j�g
        type[3] = type[3] - 32;
    }
    char4_sum = hp[3] + atk[3] + def[3]; //����4��O�ƭ��`�M
    if (hp[3]<40 || hp[3]>50 || atk[3]<15 || atk[3]>20 || def[3]<5 || def[3]>10 || char4_sum<65 || char4_sum>70){
        printf("���~�G��O�ƭȦb����d�򤧥~\n");
        correct = 0;
                    }
    printf("\n");
    }while (!correct);
        *n_Addr = 4; //��ܨ����T�ɡA�h��ܨ���4��T
}

void PrintCharData(){ //�禡�G��ܨ����T 
    int i; //for�j���ܼ�
    for (i=0; i<n; i++){ //�L�X����1~3�Ҧ��ƭȡA����1(i=0)�A����2(i=1)�A����3(i=2)
        printf("����%d\n", i+1);
        printf("����W�١G%s\n", char_name[i]);
        printf("�ݩʡG%-6c��q�G%d\n" ,type[i] ,hp[i]); //�ݩʡB��q
        printf("�����G%-6d���m�G%d\n" ,atk[i] ,def[i]); //�����B���m
        power = (hp[i]*1 + atk[i]*0.8 + def[i]*0.5 - 50)*6.5; //�j�׹w���G[(��q*1+����*0.8+���m*0.5)-50]*6.5
        printf("����j�׹w���G%.2lf\n\n", power); //�j�׹w��
    }
}

void SelectAndBattle(){ //�禡�G�ܥ����A���۶iBattling�԰��禡
    do {
        correct = 1; //��l��flag
        printf("��ܥ��𨤦�G");
        scanf("%d", &st_char);
        if (st_char<1 || st_char>n){ //�p�G���𨤦⸹�p��1�A�Τj��n=3(���s�W����)/n=4(���s�W����)
            printf("���~�G�L������\n");
            correct = 0;
        }
    }while (!correct);
    do {
        correct = 1; //��l��flag
        printf("��ܫ�𨤦�G");
        scanf("%d", &nd_char);
        if (nd_char<1 || nd_char>n){ //�p�G��𨤦⸹�p��1�A�Τj��n=3(���s�W����)/n=4(���s�W����)
            printf("���~�G�L������\n");
            correct = 0;
        }else if (nd_char == st_char){
            printf("���~�G���i���ƿ��\n");
            correct = 0;
        }
    }while (!correct);
    //���𨤦��ƨ��X
    st_type = type[st_char-1];
    st_hp = hp[st_char-1];
    st_half_hp = st_hp / 2; //���𨤦�A�b��ƭ�
    st_atk = atk[st_char-1];
    st_def = def[st_char-1];
    //��𨤦��ƨ��X
    nd_type = type[nd_char-1];
    nd_hp = hp[nd_char-1];
    nd_half_hp = nd_hp / 2; //��𨤦�A�b��ƭ�
    nd_atk = atk[nd_char-1];
    nd_def =  def[nd_char-1];

    if (st_type == 'A'){ //�ݩʬ۫g�P�_�A�����ݩ�A
        if (nd_type == 'F'){
            first_type_atk = 0.8;
            second_type_atk = 1.2;
        }else if (nd_type == 'G'){
            first_type_atk = 1.2;
            second_type_atk = 0.8;
        }else {
            first_type_atk = 1;
            second_type_atk = 1;
        }
    }
    if (st_type == 'G'){ //�ݩʬ۫g�P�_�A�����ݩ�G
        if (nd_type == 'A'){
            first_type_atk = 0.8;
            second_type_atk = 1.2;
        }else if (nd_type == 'W'){
            first_type_atk = 1.2;
            second_type_atk = 0.8;
        }else {
            first_type_atk = 1;
            second_type_atk = 1;
        }
    }
    if (st_type == 'F'){ //�ݩʬ۫g�P�_�A�����ݩ�F
        if (nd_type == 'W'){
            first_type_atk = 0.8;
            second_type_atk = 1.2;
        }else if (nd_type == 'A'){
            first_type_atk = 1.2;
            second_type_atk = 0.8;
        }else {
            first_type_atk = 1;
            second_type_atk = 1;
        }
    }
    if (st_type == 'W'){ //�ݩʬ۫g�P�_�A�����ݩ�W
        if (nd_type == 'G'){
            first_type_atk = 0.8;
            second_type_atk = 1.2;
        }else if (nd_type == 'F'){
            first_type_atk = 1.2;
            second_type_atk = 0.8;
        }else {
            first_type_atk = 1;
            second_type_atk = 1;
        }
    }
    first_sum_atk = st_atk * first_type_atk - nd_def; //���������p��
    second_sum_atk = nd_atk * second_type_atk - st_def; //��������p��
    Battling();
}

void Battling(){ //�禡�G�԰�
    while(st_hp>0 && nd_hp>0){
        printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", st_char, nd_char, first_sum_atk);
        nd_hp = nd_hp - first_sum_atk;
        printf("����%d HP�G%d  ����%d HP�G%d\n", st_char, st_hp, nd_char, nd_hp);
        printf("\n");
        if (nd_hp < nd_half_hp){ //����q�C��50%�A�[�W�ݼg���v
            second_sum_atk = (nd_atk * second_type_atk * 1.2 - st_def);
        }
        if (nd_hp<=0 && st_hp!=0){
            printf("����%d ���h�԰���O\n", nd_char);
            printf("�԰�����\n");
            printf("\n");
            printf("����%d ���",st_char);
            printf("\n\n");
            break;
        }
        printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n", nd_char, st_char, second_sum_atk);
        st_hp = st_hp - second_sum_atk;
        printf("����%d HP�G%d  ����%d HP�G%d\n", st_char, st_hp, nd_char, nd_hp);
        printf("\n");
        if (st_hp < st_half_hp){ //�����q�C��50%�A�[�W�ݼg���v
            first_sum_atk = (st_atk * first_type_atk * 1.2 - nd_def);
        }
        if (st_hp<=0 && nd_hp!=0){
            printf("����%d ���h�԰���O\n", st_char);
            printf("�԰�����\n");
            printf("\n");
            printf("����%d ���", nd_char);
            printf("\n\n");
            break;
        }
    }
}
