using System;
using System.Collections;
using System.Collections.Generic;

class PrimeCollection : IEnumerable<int>, IEnumerator<int>
{
    List<int> prime_list;
    int current, k;
    bool inRange;


    public PrimeCollection()
    {
        this.prime_list = new List<int>();
        this.current = 2;
        this.k = 0;
        this.inRange = true;
    }


    private bool IsPrime(int n)
    {
        for(int i=2; i<n; i++){
            if(n%i == 0) return false;
        }
        return true;
    }

    public int Element()
    {

        while(true)
        {
            if(IsPrime(current))
            {
                this.prime_list.Add(this.current);
                this.current++;  
                break;    
            }
            if(current >= Int32.MaxValue)
            {
                inRange = false;
                break;
            }
            this.current++;
        }
        return this.prime_list[k-1];
    }


    public IEnumerator<int> GetEnumerator()
    {
        return this;
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return this;
    }

    public int Current
    {
        get
        {
            return Element();
        }
    }

    object IEnumerator.Current
    {
        get
        {
            return Current;
        }
    }

    public bool MoveNext()
    {
        k++;
        return inRange;
    }


    public void Reset()
    {
        k = 0;
    }

    public void Dispose() {}
}

class Program
{
    static void Main(string[] args)
    {
        PrimeCollection pc = new PrimeCollection();
        foreach(int p in pc)
            Console.WriteLine(p);
    }
}