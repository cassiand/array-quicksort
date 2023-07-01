// cassian
// 11/6/22
// week 9 assignment
// random population of an array, then implementation of quicksort algorithm on array

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class userArray
{
private:
    vector<int>(theVect);         // declare vector of doubles
    int nElems;                      // declare number of data items
public:

    userArray(int max) : nElems(0)       // constructor
    {
        theVect.resize(max);             // resize the vector
    }

    void insert(int value)           // method to put element in array
    {
        theVect[nElems] = value;         // insert it
        nElems++;                        // increment size
    }

    void display()                      // displays array
    {
        cout << "Array = " << endl;
        for (int j = 0; j < nElems; j++)      // for each element,
            if (j % 25 != 0)                  // if remainder of j / 25 != 0,
                cout << theVect[j] << " ";    // then print with tab after
            else if (j == 0)                  // or if j is first element
                cout << theVect[j] << " ";
            else
                cout << theVect[j] << endl;   // otherwise, print with endl for formatting
            
        cout << endl;
    }

    void quickSort()                    // method to quicksort array
    {
        recQuickSort(0, nElems - 1);       // call recursive sort
    }

    void recQuickSort(int left, int right)  // recursive sort
    {
        if (right - left <= 0)                  // if size <= 1,
            return;                          //   already sorted
        else                                 // if size is 2 or larger
        {
            double pivot = theVect[right];    // rightmost item
            //partition range
            int partition = partitionIt(left, right, pivot);
            recQuickSort(left, partition - 1);  // sort left side
            recQuickSort(partition + 1, right); // sort right side
        }
    }  //end recQuickSort()

    int partitionIt(int left, int right, double pivot)
    {
        int leftMark = left - 1;           // left    (after ++)
        int rightMark = right;           // right-1 (after --)
        while (true)
        {                             // find bigger item
            while (theVect[++leftMark] < pivot)
                ;                          //   (nop)
                                           // find smaller item
            while (rightMark > 0 && theVect[--rightMark] > pivot)
                ;                          //   (nop)

            if (leftMark >= rightMark)     // if pointers cross,
                break;                     //   partition done
            else                          // not crossed, so
                swap(leftMark, rightMark); //   swap elements
        }  //end while(true)
        swap(leftMark, right);           //restore pivot
        return leftMark;                 //return pivot location
    }  //end partitionIt()

    void swap(int dex1, int dex2)       //swap two elements
    {
        double temp = theVect[dex1];     // A into temp
        theVect[dex1] = theVect[dex2];   // B into A
        theVect[dex2] = temp;            // temp into B
    }  //end swap(

};


int main()
{
    time_t timeVar;             // create obj of time_t
    int maxSize = 250;          // set array max size
    userArray arr(maxSize);     // create obj of userArray class with size of 250
    srand(static_cast<unsigned>(time(&timeVar)));   // seed randoms

    for (int i = 0; i < maxSize; i++)   // insert random ints into array
    {
        int x = rand() % 99;
        arr.insert(x);
    }
    arr.display();      // call print method
    arr.quickSort();    // call quicksort method
    arr.display();      // call print method again
    return 0;

}


