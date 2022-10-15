#include <iostream>
#include<iomanip>
#include<string>
#include<cmath>
//#include<bits/stdc++.h>
//#include<bits/bits-stdc++.h>
#define all(x)                  (x).begin(),(x).end()
using namespace std;

class Array {
private:
    int size, length;
    int* items;
public:
    Array(int arrsize) {

        size = arrsize;
        length = 0;
        items = new int[arrsize];
    }
    void Fill() {
        cout << "How many items you want fill\n";
        int n_items;
        cin >> n_items;
        if (n_items > size) {
            cout << "You cannot axceed the arry size\n";
            return;
        }
        else {
            for (int i = 0;i < n_items;i++) {
                cout << "please enter value of item " << i + 1 << "\t";
                cin >> items[i];
                cout << "\n";
                length++;
            }
        }
    }
    int getsize() {
        return size;
    }
    int getlength() {
        return length;
    }
    void Disply() {
        cout << "Disply array items\n";
        for (int i = 0;i < length;i++) {
            cout << items[i] << " ";
        }
        cout << "\n";
    }

    int Search(int Key) {
        int indx = -1;
        for (int i = 0;i < length;i++) {
            if (items[i] == Key) {
                indx = i;
                break;
            }
        }
        return indx;
    }

    void Appand(int Newitem) {
        if (length < size) {
            items[length] = Newitem;
            length++;
        }
        else
            cout << "Array is full\n";
    }

    void Insert(int indx, int Newitem) {
        if (indx >= 0 && indx < size && length < size) {
            for (int i = length;i > indx;i--) {
                items[i] = items[i - 1];
            }
            items[indx] = Newitem;
            length++;
        }
        else
            cout << "Erro - indx ot of the range\n";
    }

    void Delete(int indx) {
        if (indx >= 0 && indx < size) {
            for (int i = indx;i < length - 1;i++) {
                items[i] = items[i + 1];
            }
            length--;
        }
        else
            cout << "Erro - indx ot of the range\n";
    }

    void Enlarge(int Newsize) {
        if (Newsize <= size) {
            cout << "New size must be large than current size\n";
        }
        else {
            size = Newsize;
            int* old = items;
            items = new int[size];
            for (int i = 0;i < length;i++) {
                items[i] = old[i];
            }
            delete[]old;
        }
    }

    void Marge(Array other) {
        int Newsize = size + other.getsize();
        size = Newsize;
        int* old = items;
        items = new int[size];
        int i;
        for (i = 0;i < length;i++) {
            items[i] = old[i];
        }
        delete[]old;
        int j = i;
        for (i = 0;i < other.getlength();i++) {
            items[j++] = other.items[i];
            length++;
        }
    }
};
int main()
{

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(0);

    // cout << fixed << setprecision(6);

    cout << "please enter size of arry\n";
    int size_of_array;cin >> size_of_array;
    Array myarray(size_of_array);

    myarray.Fill();

    cout << "size = " << myarray.getsize() << "\t" << "length = " << myarray.getlength() << "\n";
    myarray.Disply();

    cout << "Enter the value to search for\n";
    int Key;cin >> Key;
    int indx = myarray.Search(Key);
    if (indx == -1)
        cout << "item not found\n";
    else
        cout << "item is found @ pos " << indx << "\n";

    int Newitem;
    cout << "Enter New item to add to the array\n";
    cin >> Newitem;
    myarray.Appand(Newitem);
    cout << "size = " << myarray.getsize() << "\t" << "length = " << myarray.getlength() << "\n";
    myarray.Disply();

    cout << "Enter the indx and item to insert\n";
    cin >> indx >> Newitem;
    myarray.Insert(indx, Newitem);
    cout << "size = " << myarray.getsize() << "\t" << "length = " << myarray.getlength() << "\n";
    myarray.Disply();

    cout << "Enter a indx to delete\n";
    cin >> indx;
    myarray.Delete(indx);
    cout << "size = " << myarray.getsize() << "\t" << "length = " << myarray.getlength() << "\n";
    myarray.Disply();

    int newsize;
    cout << "Enter New size of array\n";
    cin >> newsize;
    myarray.Enlarge(newsize);
    cout << "size = " << myarray.getsize() << "\t" << "length = " << myarray.getlength() << "\n";
    myarray.Disply();

    Array other(3);
    other.Fill();
    myarray.Marge(other);
    cout << "size = " << myarray.getsize() << "\t" << "length = " << myarray.getlength() << "\n";
    myarray.Disply();
    return 0;
}