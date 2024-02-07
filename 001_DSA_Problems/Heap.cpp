//We can use this HEAP concept using STL Priority Queue
#include<iostream>

using namespace std;

class heap {
    public:
        int values[100];
        int size;

        heap() {
            values[0] = -1;
            size = 0;
        }

        void insert(int val) {
            size++;
            int index = size;
            values[index] = val;

            while (index > 1)
            {
                int parent = index / 2;     //O(LOG N)

                if (values[parent] < values[index])
                {
                    swap(values[parent], values[index]);
                    index = parent;
                }
                else {
                    return;
                }
            }
        }

        void deleteNode() {     //always delete 1st / root element.
            if (size == 0) {
                cout<<"Heap is Empty!!!"<<endl;
                return;
            }

            //step 1
            //insted of deleting the root node directly put last element --> root node
            //you can swap those 2 elements but its expensive

            values[1] = values[size];

            //step 2
            //remove last element
            size--;

            //step 3
            //take root node to its correct poition.
            int i = 1;
            while (i < size)
            {
                int leftNode = 2 * i;
                int rightNode = (2 * i) + 1;

                if (leftNode < size && values[i] < values[leftNode])
                {
                    swap(values[i], values[leftNode]);
                    i = leftNode;       //if we change in left node we have to go to left sub-tree.
                }
                else if (rightNode < size && values[i] < values[rightNode])
                {
                    swap(values[i], values[rightNode]);
                    i = rightNode;      //if we change in right node we have to go to right sub-tree.
                }
                else return;
            }
            
        }

        void printH() {
            cout<<"HEAP: ";
            for (int i = 1; i <= size; i++)
            {
                cout<<values[i]<<", ";
            }
            cout<<endl;
        }
};

void heapify(int arr[], int n, int i) {     //arr --> heap, n --> size of heap, i --> from which node want to heapify.
    int largest = i;
    int left = 2 * i;
    int right = (2 * i) + 1;

    //just find largest element's index beween 3 nodes parent, Lchild, Rchild
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    
    //look for change
    if (largest != i)
    {
        //swap largest element with current element
        swap(arr[largest], arr[i]);
        //look for sub-tree
        heapify(arr, n, largest);
    }
    
}

void sort(int arr[], int n) {
    int size = n;
    while (size > 1)
    {
        //Step 1: you know the 1st element is largest so, just swap it with last element.
        swap(arr[size], arr[1]);

        //step 2: then arrenge that last element to it's correct position who is now at 1st position.
        heapify(arr, size, 1);
        size--;
    }
}

int main(void)
{
    heap h1;
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);
    cout<<"After Insertion."<<endl;
    h1.printH();
    h1.deleteNode();
    cout<<"After Deletion."<<endl;
    h1.printH();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    cout<<"heapified array: "<<endl;
    //to get the last internal node in 1 based indexing do n/2
    int lastIntenalN = n/2;
    for (int i = lastIntenalN; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    
    cout<<"HEAP: ";
    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<", ";
    }
    cout<<endl;
    
    cout<<"sorted array: "<<endl;
    sort(arr, n);
    cout<<"HEAP: ";
    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<", ";
    }
    return 0;
}