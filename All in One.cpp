#include<bits/stdc++.h>
using namespace std;
void Bubble(vector<int> &arr)
{
    bool swapped;
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        swapped=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swapped=true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(swapped==false)
        {
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void selection(vector<int> &arr)
{
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void insertion(vector<int> &arr)
{
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        int j=i;
        while(j>0 and arr[j-1]>arr[j])
        {
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void merge(vector<int> &arr, int low, int mid,int high)
{
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid and right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
}
void mergesort(vector<int> &arr,int low,int high)
{
    if(low>=high)return;
    int mid=low+(high-low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int partition(vector<int>&arr, int s,int e)
{
    
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {
            count++;
        }
    }
    int pivotIndex=s+count;
    swap(arr[pivotIndex],arr[s]);
    int i=s, j=e;
    while(i<pivotIndex and j>pivotIndex)
    {
        while(arr[i]<pivot)
        {
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex and j>pivotIndex)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void QuickSort(vector<int> &arr, int s, int e)
{
    if(s>=e){
        return;
    }
    int p=partition(arr,s,e);
    QuickSort(arr,s,p-1);
    QuickSort(arr,p+1,e);
}
int main()
{
    vector<int> arr={2,3,1,9,6,10,7};
    int n=arr.size();
    // Bubble(arr);
    // selection(arr);
    // insertion(arr);
    // mergesort(arr,0,n-1);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
