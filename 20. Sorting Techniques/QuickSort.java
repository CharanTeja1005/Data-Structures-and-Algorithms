import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class QuickSort {
    public static int partition(int[] arr,int l,int h)
    {
        int pivot = arr[l];
        int i = l;
        int j = h;
        while(i < j)
        {
            while(arr[i] <= pivot && i < h)
                i++;
            while(arr[j] > pivot)
                j--;
            if(i < j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        arr[l] = arr[j];
        arr[j] = pivot;
        return j;
    }
    public static void quickSort(int arr[],int l,int h)
    {
        if(l < h)
        {
            int j = partition(arr,l,h);
            quickSort(arr,l,j);
            quickSort(arr,j+1,h);
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
        quickSort(arr,0,n-1);
        System.out.print("Elements after sorting  : ");
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
