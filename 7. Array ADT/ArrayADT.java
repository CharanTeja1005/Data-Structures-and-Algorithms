import java.io.*;

class A
{
    int[] array;
    int size;
    int length;
    A()
    {
        this.length = 0;
    }
    A(int size)
    {
        this.array = new int[size];
        this.size = size;
        this.length = 0;
    }

    public void display()
    {
        for(int i=0;i<this.length;i++)
        {
            System.out.print(this.array[i] + " ");
        }
        System.out.println();
    }

    public void add(int x)
    {
        if(this.length < this.size)
        {
            this.array[this.length] = x;
            this.length++;
        }
    }

    public void insert(int index,int x)
    {
        if(index > 0 && index <=this.length)
        {
            for(int i=this.length;i>index;i--)
            {
                this.array[i] = this.array[i-1];
            }
            this.array[index] = x;
            this.length++;
        }
    }
}

public class ArrayADT
{
    public static void main(String[] args) throws IOException
    {
        A ar= new A();
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // System.out.print("Enter the size of Array : ");
        // ar.size = Integer.parseInt(br.readLine());
        // ar.array = new int[ar.size];
        // System.out.print("Enter the number of elements : ");
        // int n = Integer.parseInt(br.readLine());
        // for(int i=0;i<n;i++)
        // {
        //     System.out.print("Enter element : ");
        //     ar.array[i] = Integer.parseInt(br.readLine());
        //     ar.length++;
        // }
        ar.array = new int[]{1,2,3,4,5};
        ar.length = 5;
        ar.display();
        ar.add(6);
        ar.display();
        ar.add(7);
        ar.display();
        ar.insert(8,8);
        ar.display();
        ar.insert(1,0);
        ar.display();
    }
}