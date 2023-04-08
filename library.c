#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int b=10;

struct details
{
    char book_name[50];
    char writer_name[50];
    int quantity;
} book[100];

int binarySearch(struct details array[], char x[], int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int y=strcmp(array[mid].book_name,x);
        if (y==0)
            return mid;

        if (y<0)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}
void merge_sort(struct details a[], int low, int high)
{
    int mid = 0;

    if(low == high)
    {
        return;
    }
    else
    {
        mid = (low + high) / 2;

        merge_sort(a, low, mid);

        merge_sort(a, mid + 1, high);

        mergee(a, low, mid, high);
    }
}
void merge_sort_writer(struct details a[], int low, int high)
{
    int mid = 0;

    if(low == high)
    {
        return;
    }
    else
    {
        mid = (low + high) / 2;

        merge_sort_writer(a, low, mid);

        merge_sort_writer(a, mid + 1, high);

        merge_writer(a, low, mid, high);
    }
}
void mergee(struct details a[], int low, int mid, int high)
{
    int i;
    int left_index = low;
    int right_index = mid + 1;
    int combined_index = low;
    struct details tempA[50];

    while(left_index <= mid && right_index <= high)
    {
        int x=strcmp(a[left_index].book_name,a[right_index].book_name);
        if(x<0)
        {
            tempA[combined_index++] = a[left_index++];
        }
        else
        {

            tempA[combined_index++] = a[right_index++];
        }
    }

    if(left_index == mid + 1)
    {
        while(right_index <= high)
        {
            tempA[combined_index++] = a[right_index++];
        }
    }
    else
    {
        while(left_index <= mid)
        {
            tempA[combined_index++] = a[left_index++];
        }
    }

    for(i = low; i <= high; i++)
    {
        a[i] = tempA[i];
    }
}
void merge_writer(struct details a[], int low, int mid, int high)
{
    int i;
    int left_index = low;
    int right_index = mid + 1;
    int combined_index = low;
    struct details tempA[50];

    while(left_index <= mid && right_index <= high)
    {
        int x=strcmp(a[left_index].writer_name,a[right_index].writer_name);
        if(x<0)
        {
            tempA[combined_index++] = a[left_index++];
        }
        else
        {

            tempA[combined_index++] = a[right_index++];
        }
    }

    if(left_index == mid + 1)
    {
        while(right_index <= high)
        {
            tempA[combined_index++] = a[right_index++];
        }
    }
    else
    {
        while(left_index <= mid)
        {
            tempA[combined_index++] = a[left_index++];
        }
    }

    for(i = low; i <= high; i++)
    {
        a[i] = tempA[i];
    }
}
void get_book(int n)
{
    if(book[n].quantity<1)
    {
        printf("Sorry you cannot get this\nWe have not enough copy\n");
        makeChoice();
    }
    else
    {
        printf("Here is your book\n");
        printf("%s %s Quantity:%d\n",book[n].book_name,book[n].writer_name,book[n].quantity);
        printf("Do you want this?if yes press Y/y:");
        char yes[5];
        scanf("%s",yes);
        if(strcmp(yes,"y")==0 || strcmp(yes,"Y")==0)
        {
            book[n].quantity--;
            printf("Here is your book\nThanks for being with us\n%d copy/copies available now\nDo you need anything else?\n",book[n].quantity);
            makeChoice();
        }
        else
        {
            printf("You took wrong choice\nDo it properly\n");
            get_book(n);
        }
    }
}
void add_book(int n)
{
    printf("Type book name,writer's name and quantity\n");
    char bn[50],wn[50];
    int qn;
    scanf("%s",bn);
    scanf("%s",wn);
    scanf("%d",&qn);
    merge_sort(book,0,n-1);
    int test=binarySearch(book,bn,0,n-1);
    if(test!=-1)
    {
        book[test].quantity=book[test].quantity+qn;
    }
    else
    {
        strcpy(book[b].book_name,bn);
        strcpy(book[b].writer_name,wn);
        book[b].quantity=qn;
        b++;
    }
    makeChoice();
}
void search_book(int n)
{
    merge_sort(book,0,n-1);
    char c[50];
    printf("which book you wanna search?\n");
    scanf("%s",c);
    int result=binarySearch(book,c,0,b-1);

    if(result==-1)
    {
        printf("Wrong keyword\nTry Consciously\n");
        search_book(n);
    }
    else
        get_book(result);
}
void printDB(int n)
{
    printf("1.Show via book's name\n2.Show via author's name\n");
    char s[5];
    scanf("%s",s);
    if(strcmp(s,"1")==0)
    {
        merge_sort(book,0,n-1);
        for(int i=0; i<n; i++)
        {
            printf("Book Name: %s\n",book[i].book_name);
            printf("Writer's name: %s\n",book[i].writer_name);
            printf("We have %d copy/copies\n\n\n",book[i].quantity);
        }
    }
    else if(strcmp(s,"2")==0)
    {
        merge_sort_writer(book,0,n-1);
        for(int i=0; i<n; i++)
        {
            printf("Writer's name: %s\n",book[i].writer_name);
            printf("Book Name: %s\n",book[i].book_name);
            printf("We have %d copy/copies\n\n\n",book[i].quantity);
        }
    }
    else
    {
        printf("Wrong choice!\nPress 1 or 2");
        printDB(n);
    }
    makeChoice();
}
void remove_book(int n)
{
    char c[50];
    printf("Which book you wanna remove?\n");
    scanf("%s",c);
    merge_sort(book,0,n-1);
    int index=binarySearch(book,c,0,n-1);
    if(index==-1)
    {
        printf("Wrong Search\nTry Consciously\n");
        remove_book(n);
    }
    else
    {
        printf("Successfully removed!\n");
        for(int j=index; j<n; j++)
        {
            strcpy(book[j].book_name,book[j+1].book_name);
            strcpy(book[j].writer_name,book[j+1].writer_name);
            book[j].quantity=book[j+1].quantity;
        }
        b--;
    }
    makeChoice();
}
void return_book(int n)
{
    printf("Type book's name you want to return\n");
    char bn[50];
    scanf("%s",bn);
    merge_sort(book,0,n-1);
    int test=binarySearch(book,bn,0,n-1);
    if(test==-1)
    {
        printf("Wrong way you did\nTry again!");
        return_book(n);
    }
    else
    {
        book[test].quantity++;
        printf("Successfully returned!\n%d copy/copies availabe now\n",book[test].quantity);
    }
    makeChoice();
}
void makeChoice()
{
    printf("Make a Choice!\n1.Add a book\n2.Search a book\n3.Remove a book\n4.Show book list\n5.Return book\nFor exit press any\n");
    int c;
    scanf("%d",&c);
    if(c==1)
        add_book(b);
    else if(c==2)
        search_book(b);
    else if(c==3)
        remove_book(b);
    else if(c==4)
        printDB(b);
    else if(c==5)
        return_book(b);
    else
        return 0;

}

int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    if(fp == NULL)
        puts("Error opening file.\n");
    else
        for(int i = 0; i < b; i++)
            fscanf(fp, "%s %s %d", book[i].book_name,book[i].writer_name, &book[i].quantity);

    makeChoice();
}
