import java.io.*;

class A
{
    int[] arr;
    int size;
    int length;
    A()
    {
        this.length = 0;
    }
    A(int size)
    {
        this.arr = new int[size];
        this.size = size;
        this.length = 0;
    }
}

public class ArrayADT
{
    public static void display(A ar)
    {
        for(int i=0;i<ar.length;i++)
        {
            System.out.print(ar.arr[i] + " ");
        }
    }

    public static void main(String[] args) throws IOException
    {
        A ar = new A();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the size of Array : ");
        ar.size = Integer.parseInt(br.readLine());
        ar.arr = new int[ar.size];
        System.out.print("Enter the number of elements : ");
        int n = Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++)
        {
            System.out.print("Enter element : ");
            ar.arr[i] = Integer.parseInt(br.readLine());
            ar.length++;
        }
        display(ar);
    }
}