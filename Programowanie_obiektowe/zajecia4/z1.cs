using System;
using System.Collections;
using System.Collections.Generic;


interface IListCollection
{
    int Element(int i);
    int Size();
}

class LazyIntList : IListCollection, IEnumerable, IEnumerator
{
    public List <Int32> lista;
    public int s, s2;
    public LazyIntList() {
        this.s=0;
        this.lista = new List<Int32>();
    }

    public int Element(int i) {
        if(this.s >= i)
        {
            return this.lista[i-1];
        }
        else
        {
            Random rd = new Random();
            for(int j=this.s; j<i; j++)
            {
                this.lista.Add(rd.Next(0,int.MaxValue));
                this.s++;
            }
            return this.lista[this.s-1];
        }
    }

    public int Size() {
        return this.s;
    }

    public int Length
    {
        get
        {
            return Size();
        }
    }

    public bool MoveNext()
    {
        s2++;
        return (s2 < 20);
    }

    public void Reset()
    {
        s2=0;
    }

    public int Current
    {
        get
        {
            return Element(s2);
        }
    }

    public IEnumerator GetEnumerator()
    {
        return this;
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return this;
    }

    object IEnumerator.Current
    {
        get
        {
            return Current;
        }
    }

    public int this[int i]
    {
        get
        {
            if (i < 0) throw new System.IndexOutOfRangeException();
            return Element(i + 1);
        }

        set
        {
            if (i < 0) throw new System.IndexOutOfRangeException();
                
            if (i >= s) Element(i + 1);
                
            lista[i] = value;
        }
    }

    public override string ToString()
    {
        if(s == 0) return null;

        return String.Format("losowa liczba całkowita: {0}", lista[s-1]);
    }
}

class Prime : IListCollection
{
    List<int> prime_list;
    int current, elements;

    public Prime()
    {
        this.prime_list = new List<int>();
        this.current = 2;
    }
    private bool IsPrime(int n)
    {
    for (int i = 2; i < n; i++)
        if (n%i == 0) return false;
            
        return true;
    }

    public int Element(int i)
    {
        if(i > elements)
        {
            int n = i-elements;

            while(n > 0)
            {
                if(IsPrime(current))
                {
                this.prime_list.Add(this.current);
                    n--;        
                }

                this.current++;
            }
            elements = i;
        }
        return this.prime_list[i-1];
    }
    public int Size()
    {
        return elements;
    }
}

class Program
{
    static void Main(string[] args)
    {
        LazyIntList lista = new LazyIntList();

        foreach (int p in lista)
        {
            Console.WriteLine(p);
        }
        Console.WriteLine(lista);
    }
}