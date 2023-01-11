import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class RadixSort {
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
    public static void countSort(int[] arr,int place,int n)
    {
        int output[] = new int[n];
        int count[] = new int[10];
        for(int i=0;i<n;i++)
            count[(arr[i]/place)%10]++;
        for(int i=1;i<n;i++)
            count[i] += count[i-1];
        for(int i=n-1;i>=0;i--)
            output[--count[(arr[i]/place)%10]] = arr[i];
        for(int i=0;i<n;i++)
            arr[i] = output[i];
    }
    public static void radixSort(int[] arr,int n)
    {
        int max = getMax(arr,n);
        for(int place=1;max/place > 0;place*=10)
        {
            countSort(arr,place,n);
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
        radixSort(arr,n);
        System.out.print("Elements after sorting  : ");
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
