void passByValue(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    return;
}

void passByReference(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    return;
}

int main(){
    int a, b;
    a = 10;
    b = 15;
    passByReference(a, b);
    passByValue(a, b);
    return 0;
}