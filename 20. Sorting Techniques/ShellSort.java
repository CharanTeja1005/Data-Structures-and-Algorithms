import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class ShellSort {
    public static void shellSort(int[] arr,int n)
    {
        for(int gap=n/2;gap>0;gap/=2)
        {
            for(int i=gap;i<n;i++)
            {
                int temp = arr[i];
                int j = i - gap;
                while(j >= 0 && arr[j] > temp)
                {
                    arr[j+gap] = arr[j];
                    j -= gap;
                }
                arr[j+gap] = temp;
            }
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
        shellSort(arr,n);
        System.out.print("Elements after sorting  : ");
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
