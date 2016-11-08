#include <iostream>
#include <vector>
#include <string>

using namespace std;

void mixSort(vector<int>& list, int left, int right, int& depth);
void quickSort(vector<int>& list, int left, int right);
void heapSort(vector<int>& values);
void Swap(int& item1, int& item2);
void ReheapDown(vector<int>& elements, int root, int bottom);

int main()
{

	int a[] = {3,2,8,5,9,1,7,6,4,10,15,13,14,11,12,13};
	 vector<int> v (a, a + sizeof(a) / sizeof(int) );
	  for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
  char letter; 

  cout << " Please choose method of sorting" << endl;
  cout << " Enter Q - Quicksort, H - Heapsort, M - Mixsort" << endl;

  cin >> letter;

  if (letter == 'Q' || letter == 'q')
  {

	 cout << "======= Quick Sorted =======" << endl;

	quickSort(v, 0, v.size() - 1);

	for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

	cout << endl;
  }
  
  else if (letter == 'H' || letter == 'h')
  {
	cout << "======== Heap Sorted =======" << endl;

	heapSort(v);

	for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

	cout << endl;
  }

  else if (letter == 'M' || letter == 'm')
  {
	cout << "======== Mix Sorted ========" << endl; 

	cout << " Please enter depth " << endl;
	int depth;

	cin >> depth;

	mixSort(v, 0, v.size() - 1, depth);

	for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

	cout << endl;
  }
	
  return 0;
}

void mixSort(vector<int>& list, int left, int right, int& depth)
{
	int i = left;
	int	j = right;
	int tmp;
	
      int pivot = list[(left + right) / 2];

      while (i <= j)  // separating the 2 halves
	  {
            while (list[i] < pivot)
                  i++;
            while (list[j] > pivot)
                  j--;
            if (i <= j)
			{
                  tmp = list[i];
                  list[i] = list[j];
                  list[j] = tmp;
                  i++;
                  j--;
            }
      }  


	  if (depth == 0) // HeapSort
	  {
		    int i;
			int j;


		// Convert the list of values into a heap.
		for (i = list.size()/2 - 1; i >= 0; i--)
			ReheapDown(list, i, list.size());

			// Sort the array.
		for (j = list.size() - 1; j > 0; j--)
		{
			std::swap(list[0], list[j]);
			ReheapDown(list, 0, j);
		}

	  }


      if (left < j) // Quicksort recursion
	  {
            depth--;
			mixSort(list, left, j, depth);
	  }

      if (i < right)
	  {
            depth--;
			mixSort(list, i, right, depth);
	  }
}

void quickSort(vector<int>& list, int left, int right)
{
	int i = left;
	int	j = right;
	int tmp;
	

      int pivot = list[(left + right) / 2];

      while (i <= j)  // separating the 2 halves
	  {
            while (list[i] < pivot)
                  i++;
            while (list[j] > pivot)
                  j--;
            if (i <= j)
			{
                  tmp = list[i];
                  list[i] = list[j];
                  list[j] = tmp;
                  i++;
                  j--;
            }
      }     

      if (left < j) // recursion
            quickSort(list, left, j);

      if (i < right)
            quickSort(list, i, right);
	  
}

void heapSort(vector<int>& values)
{
	int i;
	int j;

    // Convert the list of values into a heap.
	for (i = values.size()/2 - 1; i >= 0; i--)
		ReheapDown(values, i, values.size());

    // Sort the array.
	for (j = values.size() - 1; j > 0; j--)
    {
		std::swap(values[0], values[j]);
		ReheapDown(values, 0, j);
    }
}

inline int leftChild(int i)
{
	return 2 * i + 1;
}

void ReheapDown(vector<int>& elements, int root, int bottom)
// Post: Heap property is restored.
{
  int child;
  int tmp;

  for (tmp = std::move(elements[root]); leftChild(root) < bottom; root = child)
  {
	  child = leftChild(root);
	  if ( child != bottom -1 && elements[child] < elements[child + 1])
		  child++;
	  if (tmp < elements[child] )
		  elements[root] = std::move(elements[child]);
	  else
		  break;
  }

  elements[root] = std::move(tmp);

  }

 
