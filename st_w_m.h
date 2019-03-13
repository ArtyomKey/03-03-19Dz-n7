class int_stack_with_max {
  private:
    int *data;
    int size;
    int capacity;
    int max;
  public:
    int_stack_with_max (int cap = 10);       //размер 10 по умолчанию
    ~int_stack_with_max ();                 // деструктор
    int operator[] (unsigned int n);
    void push(const int x );     // поместить элемент в вершину стека
    int pop();                  // удалить элемент из вершины стека и вернуть его
    int getsize();
    int get_max();
};

int_stack_with_max ::int_stack_with_max (int cap){
  capacity = cap;
  data = new int[cap];
  size = max = 0;
}

int_stack_with_max ::~int_stack_with_max (){
  delete [] data;
  capacity = 0;
  size = max = 0;
}

void int_stack_with_max ::push(const int x){
  if(size >= capacity){
    capacity*= 2;
    int* temp = new int[capacity];
    for(unsigned int i = 0; i < size; i++){
      temp[i] = data[i];
    }
    delete [] data;
    data = temp;
  }
  data[++size] = x;
  if(x > max){
    max = x;
  }
}

int int_stack_with_max ::pop(){
  if(data[size] == max){
    max = 0;
    for(int i = 0; i < size-1; i++){
      if(data[i] > max){
        max = data[i];
      }
    }
  }
  return data[size--];
}

int int_stack_with_max ::operator[] (unsigned int n){
  return data[n];
}

int int_stack_with_max ::getsize(){
  return size;
}
int int_stack_with_max ::get_max(){
  return max;
}