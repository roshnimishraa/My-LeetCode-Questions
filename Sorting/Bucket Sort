No. Buckets if it's uniformly distributed -> N/k 
N = max(arr)  + 1
k = no. of buckets

Time Complexity 
Best Case : O(N) 
Worst Case : 
All items go inta a single bucket, if we use Insertion sort to sort the individual buckets, then O(N)^2 

If we use O(n logn) algorithm to sort the individual buckets then TC : O(n * log n ) 

Auxiliary Space: O(n+k)

Algorithm 

void bucketSort(float arr[], int n)
{

    // 1) Create n empty buckets
    vector<float> b[n];

    // 2) Put array elements
    // in different buckets
    for (int i = 0; i < n; i++) {

        // Index in bucket
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}
