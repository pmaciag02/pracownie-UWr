using System;
using System.Collections.Generic;

class LazyIntList {
    public List <Int32> lista;
    public int s;
    public LazyIntList() {
        this.s=0;
        this.lista = new List<Int32>();
    }

    virtual public int element(int i) {
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

    public int size() {
        return this.s;
    }
}

class LazyPrimeList : LazyIntList {
    public LazyPrimeList() {

    }

    override public int element(int i) {
        int licznik=0;
        if(this.s >= i)
        {
            return this.lista[i-1];
        }
        else
        {
            if(this.s == 0)
            {
                this.lista.Add(2);
                this.s=1;
            }
            else if(this.s == 1)
            {
                this.lista.Add(3);
                this.s=2;
            }
            
            int a = this.lista[this.s-1];
            
            
            for(int l=this.s; l<i; l++){
                a+=2;
            for (int m=3; m <= Math.Sqrt(a); m+=2){
                if(a%m == 0)
                {

                    if(a == int.MaxValue)
                    {
                        Console.WriteLine("przekroczenie INT_MAX");
                        return int.MaxValue;
                    }
                    else
                    {
                        m=1;
                        a+=2;
                    }
                }
            }
            this.lista.Add(a);
            licznik++;
            }

            this.s+=licznik;
            return this.lista[i-1];
        }
    }
}


class MojProgram {
public static void Main() {

LazyIntList lista = new LazyIntList();
Console.WriteLine("Długość pustej listy: {0}", lista.s);
Console.WriteLine("Dodanie losowego elementu: {0}", lista.element(40));
Console.WriteLine("Długość listy: {0}", lista.s);
Console.WriteLine("Dodanie losowego elementu: {0}", lista.element(38));
Console.WriteLine("Długość listy: {0}", lista.s);
Console.WriteLine("Dodanie losowego elementu: {0}", lista.element(50));
Console.WriteLine("Długość listy: {0}", lista.s);

LazyPrimeList lazyl = new LazyPrimeList();
Console.WriteLine("Długość pustej listy: {0}", lazyl.s);
Console.WriteLine("Dodanie elementu: {0}", lazyl.element(1));
Console.WriteLine("Długość listy: {0}", lazyl.s);
Console.WriteLine("Dodanie elementu: {0}", lazyl.element(4));
Console.WriteLine("Długość listy: {0}", lazyl.s);
Console.WriteLine("Dodanie elementu: {0}", lazyl.element(2));
Console.WriteLine("Długość listy: {0}", lazyl.s);
Console.WriteLine("Dodanie elementu: {0}", lazyl.element(3));
Console.WriteLine("Długość listy: {0}", lazyl.s);
}
}