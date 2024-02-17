using System;


class IntStream {
   public int currentValue;

    public IntStream() {
        this.currentValue = -1;
    }
    virtual public int next() {
        this.currentValue+=1;
        return this.currentValue;
    }
    public bool eos() {
        if(this.currentValue == int.MaxValue)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public void reset() {
        this.currentValue=0;
    }
}

class PrimeStream : IntStream {
        public PrimeStream() {

        }

        override public int next() {
            int a = this.currentValue;

            if(a < 2)
            {
                this.currentValue=2;
                return 2;
            }
            else if(a < 3)
            {
                this.currentValue=3;
                return 3;
            }
            a+=2;
            for (int i=3; i <= Math.Sqrt(a); i+=2){
                if(a%i == 0)
                {

                    if(base.eos())
                    {
                        Console.WriteLine("przekroczenie INT_MAX");
                        return int.MaxValue;
                    }
                    else
                    {
                        i=1;
                        a+=2;
                        this.currentValue=a;
                    }
                }
            }
            this.currentValue=a;
            return a;
        }

    }
class RandomStream : IntStream {
        public RandomStream() {

        }
        override public int next() {
            Random rd = new Random();
            this.currentValue=rd.Next(0, int.MaxValue);
            return this.currentValue;
        }
    }


class RandomWordStream {
    public string s;
    public string t = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    public PrimeStream n;
    public RandomWordStream() {
        this.s="";
        this.n = new PrimeStream();
    }

    public string next() {
        int k = this.n.next();
        Random rd = new Random();
        string st="";

        for(int i=0; i<k; i++)
        {
            st+=this.t[rd.Next(0,35)];
        }
        return st;
    }

}

class MojProgram {
public static void Main() {

IntStream x = new IntStream();
Console.WriteLine("Kolejne liczby naturalne: {0} {1} {2} {3}", x.next(), x.next(), x.next(), x.next());

PrimeStream ps = new PrimeStream();
Console.WriteLine("Kolejne liczby pierwsze: {0} {1} {2} {3}", ps.next(), ps.next(), ps.next(), ps.next());

RandomStream rs = new RandomStream();
Console.WriteLine("Kolejne losowe liczby naturalne: {0} {1} {2} {3}", rs.next(), rs.next(), rs.next(), rs.next());

RandomWordStream rws = new RandomWordStream();
Console.WriteLine("Kolejne losowe  stringi: {0} {1} {2} {3}", rws.next(), rws.next(), rws.next(), rws.next());
}
}