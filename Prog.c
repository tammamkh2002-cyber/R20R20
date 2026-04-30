#include <stdio.h>               //للادخال والاخراج
#include <string.h>              //للتعامل مع النصوص

#define SIZE 60   //حجم المخزن الدائري 60

//تعريف المخزن الدائري
typedef struct {
    char buffer[SIZE];  //مصفوفة التخزين
    int head;    //مؤشر القراءة
    int tail;    //مؤشر الكتابة
    int count;   //عدد العناصر في المخزن
}CircularBuffer;   //اسم المخزن 


//تهيئة المخزن 
void init(CircularBuffer *buff) {
    buff->head =0;
    buff->tail =0;
    buff->count =0;
}


//التحقق اذا كان المخزن ممتلئ
int isFull(CircularBuffer *buff) {
    return buff->count == SIZE;
}


// التحقق اذا كان المخزن فارغ
int isEmpty(CircularBuffer *buff) {
    return buff->count == 0;
}


// كتابة عنصر داخل المخزن
void writeBuffer(CircularBuffer *buff, char data) {
    if (isFull(buff)) {
        printf("\nBuffer Overflow\n");
        return;
    }

    buff->buffer[buff->tail] = data;
    buff->tail = (buff->tail + 1) % SIZE;
    buff->count++;
}


// قراءة عنصر من المخزن
char readBuffer(CircularBuffer *buff) {
    if (isEmpty(buff)) {
        printf("\nBuffer Underflow\n");
        return '\0';
    }

    char data = buff->buffer[buff->head];
    buff->head = (buff->head + 1) % SIZE;
    buff->count--;

    return data;
}


// البرنامج الرئيسي
int main() {

    CircularBuffer cb;
    init(&cb);

    char name[100];

    // إدخال الاسم
    printf("Enter your name:");
    scanf("%s",name);

    // إضافة النص
    strcat(name,"ESY-CE");

    // تخزين النص في المخزن
    for (int i = 0; i < strlen(name); i++) {
        writeBuffer(&cb, name[i]);
    }

    // قراءة وطباعة المحتوى
    printf("\nOutput: ");

    while (!isEmpty(&cb)) {
        printf("%c", readBuffer(&cb));
    }
    if (isEmpty(&cb)) {
    printf("\nBuffer is empty\n");
}

    printf("\n");

    return 0;
}
