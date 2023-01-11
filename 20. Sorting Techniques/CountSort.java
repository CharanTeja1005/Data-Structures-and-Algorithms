import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class CountSort {
    public static int getMax(int[] arr,int n)
    {
        int max = Integer.MIN_VALUE;
        for(int i=0;i<n;i++)
        {
            if(arr[i] > max)
                max = arr[i];
        }
        return max;
    }
    public static void countSort(int[] arr,int n)
    {
        int max = getMax(arr,n);
        int count[] = new int[max + 1];
        for(int i=0;i<n;i++)
            count[arr[i]]++;
        int i = 0;
        int k = 0;
        while(i<count.length)
        {
            if(count[i] > 0)
            {
                arr[k++] = i;
                count[i]--;
            }
            else
                i++;
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
        countSort(arr,n);
        System.out.print("Elements after sorting  : ");
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
