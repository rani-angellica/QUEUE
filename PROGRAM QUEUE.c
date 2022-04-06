#include<stdio.h>
#define MAX 3

typedef struct {
    int data[MAX];
    int head;
    int tail;

}Queue;

Queue antri;

void Awal()
{
    antri.head=antri.tail=-1;
}

int kosong()
{
    if(antri.tail==-1)
        return 1;
    else
        return 0;
}

int penuh()
{
    if(antri.tail==MAX-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void masuk(int data)
{
    if(kosong()==1)
    {
        antri.head = antri.tail = 0;
        antri.data[antri.tail]= data;
        printf("%d masuk",antri.data[antri.tail]);
        void tampil()
        {
            if(kosong()==0)
            {
                for(int i=antri.head; i<=antri.tail; i++)
                {
                    printf("%d", antri.data[i]);
                }
            }else
        printf("antrian kosong");
        }

    }
    else if (penuh()==0)
    {
    antri.tail++;
    antri.data[antri.tail]=data;
    printf("%d masuk", antri.data[antri.tail]);
    }
}


int keluar()
{
    int d= antri.data[antri.head];
    for(int i=antri.head; i<=antri.tail-1; i++)
    {
        antri.data[i]= antri.data[i+1];
    }
    antri.tail--;
    return d;
}

void tampil()
{
    if(kosong()==0)
    {
        for(int i=antri.head; i<= antri.tail; i++)
        {
            printf("%d", antri.data[i]);
        }
    }


}

void hapus()
{
    antri.head=antri.tail=-1;
    printf("data dalam antrian telah di hapus");
}

int main()
{
    int pilih;
    int data;
    Awal();
    do{
    printf("\n========================\n");
    printf("     PROGRAM QUEUE\n");
    printf("========================\n");
    printf("1. Masuk satu data\n");
    printf("2. Keluar satu data\n");
    printf("3. Liat isi antrian\n");
    printf("4. Hapus isi antrian\n");
    printf("5. Keluar\n");
    printf("========================\n");
    printf("Pilihan anda : ");
    scanf("%d", &pilih);
    switch(pilih)
    {
        case 1:
            printf("data = ");
            scanf("%d", &data);
            masuk(data);
            break;
        case 2:
            printf("data yg keluar : %d", keluar());
            break;
        case 3:
            tampil();
            break;
        case 4:
            hapus();
            break;
    }
}while(pilih!=5);
}
