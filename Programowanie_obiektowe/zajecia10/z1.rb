class Collection

    def initialize
        @list = Array.new
        @length = 0
    end



    def swap(i, j)
        if i <= 0 || i > @length
            print "Podano niepoprawną pozycję: brak elementu\n"
        elsif j <= 0 || j > @length
        print "Podano niepoprawną pozycję: brak elementu\n"
        else
            temp = @list[i]
            @list[i] = @list[j]
            @list[j] = temp
        end
    end



    def length
        return @length
    end



    def get(i)
        if i <= 0 || i > @length
            print "Podano niepoprawną pozycję: brak elementu #{i}\n"
        else
            return @list[i]
        end
    end




    def push(x)
        @length += 1
        @list[@length] = x
    end




    def print_list
        if @length == 0
            print "Lista jest pusta\n"
        else
            1.upto(@length-1) do |i|
                print @list[i], ", "
            end
            print @list[@length], "\n"
        end
    end
end



class Sorter

    def sort1(list) # selection sort, O(n^2)
        1.upto(list.length) do |i|
            min = i
            (i + 1).upto(list.length) do |j|
                if list.get(j) < list.get(min)
                    min = j
                end
            end
            list.swap(i, min)
        end
    end




    def sort2(list) # merge sort, O(n*sqrt(n)), szybsze
        self.merge_sort(1, list.length, list)
    end




    def merge_sort(l, r, ls)
        if l < r
            m = (l + r) / 2
            merge_sort(l, m, ls)
            merge_sort(m + 1, r, ls)

            temp = m + 1

            while l <= m && temp <= r
                if ls.get(l) > ls.get(temp)
                    temp2 = temp
                    while temp2 > l
                        ls.swap(temp2 - 1, temp2)
                        temp2 -= 1
                    end
                    m += 1
                    temp += 1
                end
                l += 1
            end
        end
    end
end



list = Collection.new
list.print_list
list.push(4)
list.push(2)
list.push(3)
list.push(-1)
list.print_list
list.swap(1, 4)
list.print_list
print list.length, "\n"

sort = Sorter.new
sort.sort1(list)
list.print_list
list.swap(1, 3)
list.swap(2, 4)
list.print_list
sort.sort2(list)
list.print_list