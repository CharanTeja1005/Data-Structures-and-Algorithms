import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Node
{
    int data;
    Node next;
    Node(){}
    Node(int data)
    {
        this.data = data;
        this.next = null;
    }
}
public class BinBucketSort {
    public static int getMax(int[] arr,int n)
    {
        int max = Integer.MIN_VALUE;
        for(int i=-0;i<n;i++)
        {
            if(arr[i] > max)
                max = arr[i];
        }
        return max;
    }
    public static void insert(Node bins[],int data)
    {
        if(bins[data] == null)
        {
            bins[data] = new Node(data);
            return;
        }
        Node p = bins[data];
        while(p.next != null)
        {
            p = p.next;
        }
        p.next = new Node(data);
    }
    public static int delete(Node bins[],int data)
    {
        bins[data] = bins[data].next;
        return data;
    }
    public static void binBucketSort(int[] arr,int n)
    {
        int max = getMax(arr,n);
        Node[] bins = new Node[max + 1];
        for(int i=0;i<n;i++)
        {
            insert(bins,arr[i]);
        }
        int k = 0;
        for(int i=0;i<bins.length;i++)
        {
            while(bins[i] != null)
                arr[k++] = delete(bins,i);
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
        binBucketSort(arr,n);
        System.out.print("Elements after sorting  : ");
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
