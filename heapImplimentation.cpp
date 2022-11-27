 #include<iostream>
 #include<math.h>
 #include<limits>
 using namespace std;
 class MinHeap
    {
     
     public :
       int *harr;//pointer to array of elements in heap
       int capacity ;//maximum possible size of min heap
       int heap_size;//current number of elements in heap


        MinHeap(int cap )
        {
            heap_size = cap ;
            capacity = cap;
            harr = new int[cap];
        }
        void linerSearch(int val)
        {
            for(int i = 0 ; i<heap_size ; i++)
            {
                if(harr[i]==val)
                {
                    cout<<"value found";
                    return;
                }
            }
            cout<<"value not found" ;
        }
        void printArray()
        {
            for(int i = 0; i< heap_size ; i++)
                cout<<harr[i]<<" ";
            cout<<endl;
        }
        int height()
        {
            return ceil(log2((heap_size + 1)) -1 ) ;
        }
        // Basic function 
        int parent ( int i )
        {
            return (i-1)/2;

        }
        int left (int i)
        {
            return  (2*i+1);
        }
        int right (int i )
        {
            return (2*i+2);
        }
        void  swap(int &a , int &b )
        {
            int temp = a;
            a = b ;
            b = temp ;

        }
        int getMin()
        {
          return harr[0];
        }
        void insertKey(int k)
        {
            if(heap_size == capacity)
            {
                cout<<"Overflow : could not insert"<<endl;
                return;
            }
            heap_size++;
            int i = heap_size -1;
            harr[i] = k;
            while(i !=0 && harr[parent(i)] > harr[i])
            {
                swap(harr[i], harr[parent(i)]);
                i = parent(i);
            }
        }
        //hepify fun
        void MinHeapify(int i ){
          int l = left(i);
          int r = right(i);
          int smallest = i;
          if(l< heap_size && harr[l] < harr[i])
              smallest = l ;
          if(r<heap_size && harr[r] < harr[smallest])
               smallest = r;
        if(smallest != i)
        {
          swap( harr[i]  ,harr[smallest]);
          MinHeapify(smallest);
        }
        }

        //extractmin
        int extractMin()
        {
          if (heap_size <= 0 )
             return INT_MAX;
          if(heap_size ==1)
          {
            heap_size--;
            return harr[0];
          }
          // store the minimum value , and remove if from help 
          int root = harr[0];
          harr[0] = harr[heap_size-1] ;
          heap_size--;
          MinHeapify(0);
          return root ;
        }
        //decrease key function
        void decreaseKey(int i , int new_val )
        {
          harr[i] = new_val ;
          while(i!= 0 && harr[parent(i)] > harr[i])
          {
            swap(harr[i] , harr[parent(i)]) ;
            i = parent(i) ;
          }
        }
        // deleteKey function 
        void deleteKey(int i )
        {
        decreaseKey(i , INT_MIN)  ;
        extractMin();
        }
        //
      


    };
 int main()
 {
    int s;
     cout<<"Enter Size of Min Heap"<<endl;
     cin>>s;
     MinHeap obj(s);
     cout<<"Min Heap Created"<<endl;
     int option , val;
     do{
  cout<<"What operation do you want to perform? "<<"select Option number . Enter 0 to exit"<<endl;
  cout<<"1.Insert key / Node / value"<<endl;
  cout<<"2. search key / node "<<endl;
  cout<<"3.Delete key/ node "<<endl;
  cout<<"4. get min  "<<endl;
  cout<<"5. Extract Min  "<<endl;
  cout<<"6. Height of Heap  "<<endl;
  cout<<"7.Print / Traversal heap value "<<endl;
  cout<<"8. clear screen "<<endl;
  cout<<"0. Exit program  "<<endl;
  cin>> option ;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "INSERT Operation -" << endl;
      cout << "Enter VALUE to INSERT in HEAP: ";
      cin >> val;
     obj.insertKey(val);
      cout << endl;
      break;
    case 2:
      cout << "SEARCH Operation -" << endl;
      cout << "Enter VALUE to SEARCH in HEAP: ";
      cin >> val;
      obj.linerSearch(val);
      break;
    case 3:
      cout << "DELETE Operation -" << endl;
      cout << "Enter INDEX of Heap Array to DELETE: ";
      cin >> val;
      obj.deleteKey(val);
      break;
    case 4:
      cout << "GET Min value : " << obj.getMin();
      cout << endl;
      break;
    case 5:
      cout << "EXTRACT Min value : " << obj.extractMin();
      cout << endl;
      break;
    case 6:
      cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
      break;

    case 7:
      cout << "PRINT Heap Array : " << endl;
      obj.printArray();

      cout << endl;
      break;

    case 8:
      system("cls");
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }


     }
     while (option !=0);
    

 }