#include<stdio.h>
#include<string.h>
#include<ctype.h>

int chosen(int a);                           //�T�{�\���ܬO�_�b�d��;
int create_type(char t);                     //�T�{�s�W/�ק﨤�⪺�ݩʬO�_�ŦX�W�w;
int create_ability(int x, int y, int z);     //�T�{�s�W/�ק﨤�⪺��O�ȬO�_�ŦX�W�w;
int member_range(int m, int n);              //�T�{�﨤�O�_�s�b;
int type_weakness(char f, char l);           //�ݩʬ۫g�P�_;
void battle(int first[], int last[], int weakness_result);         //�԰�

int main()
{
    char name[5][21] = { " ","RTRT","DK","Hue"," " };    //����W�١Aname[1]�Bname[2]...���O�����쨤��1�B2�B3�B4���W��;
    char type[5] = { ' ','F','G','W',' ' };              //�����ݩʡA�ƧǦP�W;
    int  hp[5]   = { 3,45,40,45,0 };                     //����ͩR�ȡA�Ĥ@��hp[0]�ΨӦs���ثe����ƶq�A��L�ƧǦP�W;
    int  atk[5]  = { 3,20,20,15,0 };                     //��������O�A�ƧǦP�W;
    int  def[5]  = { 3,5,10,10,0 };                      //���⨾�m�O�A�ƧǦP�W;
    float  combat[5] = { 3,0,0,0,0 };                    //����j�׹w���A�ƧǦP�W;

    for (int i = 1; i < 4; i++)    //�p�⨤��1~3���j�׹w��;
    {
        combat[i] = (hp[i] * 1.0 + atk[i] * 0.8 + def[i] * 0.5 - 50) * 6.5;
    }

    while (1)
    {
        int choose = 0;        //�P�_�\���ܪ��ܼ�;
        printf("1. �s�W�έק�s�W����\n"
               "2. ��ܩҦ�������\n"
               "3. �԰�\n"
               "0. �����C��\n");
        printf("�п�ܡG");
        scanf("%d", &choose);
        getchar();
        printf("\n");

        if (chosen(choose))      //�Y��J�Ȥ��ŦX�W�w�A�禡�|�^��1�A�í��m�j��;
        {
            printf("��J���~!\n\n");
            continue;
        }
        else if (choose == 0)    //��J0�A�����C��;
        {
            printf("�����C��\n\n");
            break;
        }
        while (choose == 1)      //��J1�A�i�J�s�W/�ק﨤��j��;
        {
            int ability_range = 1;    //�P�_��O�ȬO�_�b�d�򤺪��ܼ�;
            int type_check = 1;       //�P�_�ݩʬO�_���T���ܼ�;

            if (hp[0] == 4)           //�Y����w��4�W�A�h�ק�s�W����A�_�h�s�W����;
                printf("�ק�s�W����\n");
            else if (hp[0] == 3)
                printf("�s�W����\n");
            printf("�W�١G");         //�N�U���ƭȦs�JArray��;
            gets(name[4]);
            printf("�ݩʡG");
            scanf("%c", &type[4]);
            printf("��q�G");
            scanf("%d", &hp[4]);
            printf("�����G");
            scanf("%d", &atk[4]);
            printf("���m�G");
            scanf("%d", &def[4]);
            getchar();

            if (islower(type[4]))    //�p�g��j�g;
                type[4] = toupper(type[4]);

            type_check = create_type(type[4]);                         //�Y�ݩʤ��X�W�d�A�^��1;
            ability_range = create_ability(hp[4], atk[4], def[4]);     //�Y��O�Ȥ��X�W�d�A�^��1;

            if (type_check || ability_range)        //�䤤�@�����X�W�d�A���m�Ш��j��;
            {
                if (type_check)                  //����ܦU�ؿ��~��];
                {
                    printf("���~�G�L���ݩ�\n");   
                    if (!ability_range)
                    {
                        printf("\n");
                    }
                }
                if (ability_range)
                    printf("���~�G��O�ƭȦb����d�򤧥~\n\n");
                
                continue;
            }   
            else        //��J���T�A�L�X����|���ƭȡA�ñN�j�׹w���s�JArray;
            {
                printf("\n����4\n"
                       "�W�١G%s\n"
                       "�ݩʡG%c     �����G%d\n"
                       "��q�G%d    ���m�G%d\n", name[4], type[4], atk[4], hp[4], def[4]);
                combat[4] =(hp[4] * 1.0 + atk[4] * 0.8 + def[4] * 0.5 - 50) * 6.5;
                printf("����j�׹w���G%.2f\n\n", combat[4]);

                if (hp[0] == 3)        //�Y�ثe�u���T�쨤��A�N��������ƶq���ȧ令�|��;
                {
                    hp[0] = 4;
                    atk[0] = 4;
                    def[0] = 4;
                    combat[0] = 4;
                }
                break;        //���Q�����u�@�A���}�j��;
            }
        }
        if (choose == 2)        //��J2�A��ܩҦ�������;
        {
            for (int i = 1; i <= hp[0]; i++)        //hp[0]�N��ثe���⪺�ƶq;
            {
                printf("����%d\n"
                       "�W�١G%s\n"
                       "�ݩʡG%c     �����G%d\n"
                       "��q�G%d    ���m�G%d\n"
                       "����j�׹w���G%.2f\n\n", i, name[i], type[i], atk[i], hp[i], def[i], combat[i]);
            }
        }
        while (choose == 3)        //��J3�A�i�J�԰��j��;
        {
            int first = 0;         //first�s�����𨤦�Alast�s����𨤦�Amember_check�P�w�������O�_�s�b;
            int last = 0;
            int member_check = 0;

            printf("��ܥ��𨤦�G");
            scanf("%d", &first);
            member_check = member_range(first, hp[0]);        //�Y������⤣�s�b�A�^��1;

            if (member_check)        //������⤣�s�b�A���m�԰��j��;
            {
                printf("���~�G�L������\n");
                continue;
            }

            int first_member[4] = { first,hp[first],atk[first],def[first] };        //����s�b�A�N���⪺�U���ƾڦs�J���𦨭���Array�A�H�K�԰��禡����;
            char first_type = type[first];    //�s���ݩ�;

            while (1)    //���﨤�j��;
            {
                member_check = 0;
                printf("��ܫ�𨤦�G");
                scanf("%d", &last);
                member_check = member_range(last, hp[0]);     //�P�W�A�Y������⤣�s�b�A�^��1;

                if (member_check)        //������⤣�s�b�A���m���﨤�j��;
                {
                    printf("���~�G�L������\n");
                    continue;
                }

                break;
            }

            if (last == first)            //���ƿ﨤�����p�A���m��Ӿ԰��j��;
            {
                printf("���~�G���i���ƿ��\n");
                continue;
            }

            int last_member[4] = { last,hp[last],atk[last],def[last] };        //����s�b�A�N���⪺�U���ƾڦs�J��𦨭���Array�A�H�K�԰��禡����;
            char last_type = type[last];    //�s���ݩ�;

            printf("\n���𬰨���%d�A��𬰨���%d\n", first, last);

            int weakness = type_weakness(first_type, last_type);      //�P�w�ݩʫg��p�A�ھڱ��p���P�|�^��1(�����J�����)�A2(����J������)�A0(�õL�۫g);
            battle(first_member, last_member, weakness);    //�i��԰��A�ǰe�����誺�ƭȥH���ݩʬ۫g������;
            break;      //�����԰��A���}�԰��j��;
        }
    }
    return 0;
}

int chosen(int a)    //�P�_�\���ܡA�Y��J�Ȥ��b0~3�h�^��1;
{
    if (a == 0 || a == 1 || a == 2 || a == 3)
        return 0;
    else
        return 1;
}

int create_type(char t)    //�ݩʤ����T�h�^��1;
{
    if (t == 'F' || t == 'W' || t == 'G' || t == 'A')
        return 0;
    else
        return 1;
}

int create_ability(int x, int y, int z)    //��O�Ƚd�򤣥��T�h�^��1;
{
    if (x >= 40 && x <= 50 && y >= 15 && y <= 20 && z >= 5 && z <= 10 && x + y + z >= 65 && x + y + z <= 70)
        return 0;
    else
        return 1;
}

int member_range(int m,int n)    //�Y�﨤���s�b�A�h�^��1;
{
    if (m > 0 && m <= n)
        return 0;
    else
        return 1;
}

int type_weakness(char f, char l)    //�P�_�ݩʫg��ΡA���إߤ@���ݩʪ�A�Τ@�Ӱj�������誺�ݩʡA�A�C�|�P�䦳�۫g���Y����L�ݩʡA�ä������ݩʬO�_����@; 
{
    char arr[5] = { 'W','F','A','G','W' };    //�b�ݩʪ��A�۳s����ӼƦr�Ҧs�J���ݩʡA���w���e�̫g����;
    int find = 0;
    while(arr[find] != f)
    {
        find++;
    }
    if (l == arr[find + 1])                  //�]���Y�����ݩʡA�b�������ǡA�O����誺�᭱(find+1)�A�h�����g�����A�^��1�A�Ϥ��h�^��2;
        return 1;
    else if (l == arr[find - 1] || (f == 'W'&&l == 'G'))    //���n�`�N�A���Ǧb��0����'W'�èS���e�@��A�]���u��W�ߦb����;
        return 2;
    else
        return 0;
}

void battle(int first[], int last[], int weakness_result)    //�԰��j��;
{
    printf("�԰��}�l\n\n");
    int first_atk;             //�ܼƤ��O�N��1.���������O�A2.��������O�A3.������q�A4.�����q�A5.�y���ˮ`�q�A�H��6.������O�_Ĳ�o�ݦ孿�v;
    int last_atk;              //�ɶq���ܰʭ쥻�Ƕi�Ӫ��ȡA�ҥH�ŧi�F�԰��M�Χ����O���ܼơA�ΨӪ������W���v;
    int first_hp = first[1];
    int last_hp = last[1];
    int damage=0;
    int flag_f = 0;
    int flag_l = 0;
    if (weakness_result == 1)    //�̷ӶǤJ��������۫g���� �uweakness_result�v �A�ӨM�w�����O���۫g���v;
    {
        first_atk = first[2] * 1.2;
        last_atk = last[2] * 0.8;
    }
    else if (weakness_result == 2)
    {
        first_atk = first[2] * 0.8;
        last_atk = last[2] * 1.2;
    }
    else
    {
        first_atk = first[2];
        last_atk = last[2];
    }
    while (first_hp > 0 && last_hp > 0)    //�p��y���ˮ`���j��A�Y���@���q�C��s�h�P�w�ӭt;
    {
        if (first_hp < first[1] * 0.5 && flag_f == 0)    //�P�w�O�_���W�ݦ孿�v�A�u�|���@��;
        {
            first_atk = first_atk * 1.2;
            flag_f = 1;
        }

        damage = first_atk - last[3];    //���v�w�g���J�����O�̭��A�ѤU�u���������m�O;
        last_hp = last_hp - damage;

        printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", first[0], last[0], damage);
        printf("����%d HP: %d  ����%d HP: %d\n\n", first[0], first_hp, last[0], last_hp);

        if (last_hp <= 0)    //�Y�����q�k�s�A���������j��;
        {
            break;
        }

        if (last_hp < last[1] * 0.5 && flag_l == 0)
        {
            last_atk = last_atk * 1.2;
            flag_l = 1;
        }

        damage = last_atk - first[3];
        first_hp = first_hp - damage;
        printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n", last[0], first[0], damage);
        printf("����%d HP: %d  ����%d HP: %d\n\n", first[0], first_hp, last[0], last_hp);
    }

    if (first_hp <= 0)    //�P�w�ӭt
    {
        printf("����%d ���h�԰���O\n", first[0]);
        printf("�԰�����\n\n");
        printf("����%d ���\n\n", last[0]);
    }
    else if (last_hp <= 0)
    {
        printf("����%d ���h�԰���O\n", last[0]);
        printf("�԰�����\n\n");
        printf("����%d ���\n\n", first[0]);
    }
}

//�ƾڭ���G
//�ݩʡGF = ���BW = ���BG = �g�BA = ���C���i��JF�BW�BG�BA�Bf�Bw�Bg�Ba�H�~���^��r���C
//��q�G40~50�����
//�����G15~20�����
//���m�G5~10�����
//�T���`�M�b65~70����

//����j�פ����G( ��q * 1.0 + ���� * 0.8 + ���m * 0.5 - 50 ) * 6.5

//�����ˮ` = (int)(����������O * �۫g���v * �ݦ孿�v - �Q�����訾�m�O)
//�ݩʬ۫g���v�G
//�ݩ����YW > F > A > G > W
//�Y���۫g���Y�G�u�ժ�1.2���A�H�ժ�0.8��
//�Y����L�۫g�h�����O�U��1.0��
//�ݦ孿�v�G�������q�p��쥻��50%�ɴݦ孿�v��1.2��