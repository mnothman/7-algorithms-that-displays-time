#include <chrono>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>


// Function prototypes
void bubbleSort(std::vector<int>& nums);
void insertionSort(std::vector<int>& nums);
void selectionSort(std::vector<int>& nums);
void mergeSort(std::vector<int>& nums);
void quickSort(std::vector<int>& nums);
void heapSort(std::vector<int>& nums);
void shellSort(std::vector<int>& nums);



int main()
{
    // Seed the random number generator
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 100);

    // Generate a random list of 20 numbers
    std::vector<int> nums;
    for (int i = 0; i < 20; i++)
    {
        nums.push_back(dist(rng));
    }

    // Print the original list of numbers
    std::cout << "Original list:" << std::endl;

    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;

    // Sort the list of numbers using each sorting algorithm and measure the elapsed time
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(nums);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " ms" << std::endl;
    std::cout << std::endl;

    start = std::chrono::high_resolution_clock::now();
    insertionSort(nums);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " ms" << std::endl;
    std::cout << std::endl;

    start = std::chrono::high_resolution_clock::now();
    selectionSort(nums);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " ms" << std::endl;
    std::cout << std::endl;

    start = std::chrono::high_resolution_clock::now();
    mergeSort(nums);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " ms" << std::endl;
    std::cout << std::endl;

    start = std::chrono::high_resolution_clock::now();
    quickSort(nums);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " ms" << std::endl;
    std::cout << std::endl;

    start = std::chrono::high_resolution_clock::now();
    heapSort(nums);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " ms" << std::endl;
    std::cout << std::endl;

    start = std::chrono::high_resolution_clock::now();
    shellSort(nums);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " ms" << std::endl;
    std::cout << std::endl;


    
    getchar(); //so the console does not immediately end

    return 0;
}
// Bubble sort algorithm
void bubbleSort(std::vector<int>& nums)
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                std::swap(nums[i], nums[i + 1]);
                swapped = true;
            }
        }
    }
    std::cout << "Bubble sort:" << std::endl;

    // Print the sorted list of numbers
    for (int num : nums)
    {
        std::cout << num << " ";
    }
}

// Insertion sort algorithm
void insertionSort(std::vector<int>& nums)
{
    for (size_t i = 1; i < nums.size(); i++)
    {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }

    // Print the sorted list of numbers
    std::cout << "Insertion Sort:" << std::endl;

    for (int num : nums)
    {
        std::cout << num << " ";
    }
}

// Selection sort algorithm
void selectionSort(std::vector<int>& nums)
{
    for (size_t i = 0; i < nums.size() - 1; i++)
    {
        size_t minIndex = i;
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(nums[i], nums[minIndex]);
    }

    // Print the sorted list of numbers
    std::cout << "Selection Sort:" << std::endl;

    for (int num : nums)
    {
        std::cout << num << " ";
    }
}

// Merge sort algorithm (recursive)
void mergeSort(std::vector<int>& nums, int start, int end)
{
    if (end - start < 2)
    {
        return;
    }

    int mid = start + (end - start) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid, end);

    std::vector<int> result;
    int i = start;
    int j = mid;
    while (i < mid && j < end)
    {
        if (nums[i] < nums[j])
        {
            result.push_back(nums[i]);
            i++;
        }
        else
        {
            result.push_back(nums[j]);
            j++;
        }
    }
    while (i < mid)
    {
        result.push_back(nums[i]);
        i++;
    }
    while (j < end)
    {
        result.push_back(nums[j]);
        j++;
    }

    for (int i = start; i < end; i++)
    {
        nums[i] = result[i - start];
    }
}

void mergeSort(std::vector<int>& nums)
{
    mergeSort(nums, 0, nums.size());

    // Print the sorted list of numbers
    std::cout << "Merge sort:" << std::endl;
    for (int num : nums)
    {
        std::cout << num << " ";
    }
}

// Quick sort algorithm (recursive)
void quickSort(std::vector<int>& nums, int start, int end)
{
    // Base case: If the list has less than 2 elements, it is already sorted
    if (end - start < 2)
    {
        return;
    }

    // Choose the pivot element
    int pivot = nums[start + (end - start) / 2];

    // Partition the list around the pivot
    int i = start;
    int j = end - 1;
    while (i <= j)
    {
        while (nums[i] < pivot)
        {
            i++;
        }
        while (nums[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            std::swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

    // Recursively sort the lower and higher partitioned lists
    quickSort(nums, start, j + 1);
    quickSort(nums, i, end);
}

void quickSort(std::vector<int>& nums)
{
    quickSort(nums, 0, nums.size());

    // Print the sorted list of numbers
    std::cout << "Quick sort:" << std::endl;
    for (int num : nums)
    {
        std::cout << num << " ";
    }
}

// Heap sort algorithm
void heapify(std::vector<int>& nums, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && nums[left] > nums[largest])
    {
        largest = left;
    }

    if (right < size && nums[right] > nums[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        std::swap(nums[i], nums[largest]);
        heapify(nums, size, largest);
    }
}

void heapSort(std::vector<int>& nums)
{
    int size = nums.size();

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(nums, size, i);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        std::swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }

    // Print the sorted list of numbers
    std::cout << "Heap sort:" << std::endl;
    for (int num : nums)
    {
        std::cout << num << " ";
    }
}

// Shell sort algorithm
void shellSort(std::vector<int>& nums)
{
    int size = nums.size();

    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = nums[i];
            int j;
            for (j = i; j >= gap && nums[j - gap] > temp; j -= gap)
            {
                nums[j] = nums[j - gap];
            }
            nums[j] = temp;
        }
    }

    // Print the sorted list of numbers
    std::cout << "Shell sort:" << std::endl;
    for (int num : nums)
    {
        std::cout << num << " ";
    }
}

