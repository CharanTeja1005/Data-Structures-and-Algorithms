import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class RecursiveMergeSort {
    public static void merge(int[] a,int l,int mid,int h)
    {
        int i = l;
        int j = mid + 1;
        int k = l;
        int b[] = new int[h+1];
        while(i <= mid && j <= h)
        {
            if(a[i] < a[j])
                b[k++] = a[i++];
            else
                b[k++] = a[j++];
        }
        while(i <= mid)
            b[k++] = a[i++];
        while(j <= h)
            b[k++] = a[j++];
        for(i=l;i<=h;i++)
            a[i] = b[i];
    }
    public static void mergeSort(int[] arr,int l,int h)
    {
        if(l < h)
        {
            int mid = (l + h)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,h);
            merge(arr,l,mid,h);
        }
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the number of elements : ");
        int n = Integer.parseInt(br.readLine());
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.print("Enter an element : ");
            arr[i] = Integer.parseInt(br.readLine());
        }
        System.out.print("Elements before sorting : ");
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        mergeSort(arr,0,n-1);
        System.out.print("Elements after sorting  : ");
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
