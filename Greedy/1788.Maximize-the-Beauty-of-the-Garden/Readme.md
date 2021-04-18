### 1788.Maximize-the-Beauty-of-the-Garden

显然，我们会用hash表来记录每种花的所有位置。比如，令某种花的第一个位置a和最后一个位置b作为两端，那么我们就只能保留区间[a:b]里的花。

那么本题是否就只是求一个区间和那么简单呢？其实不然，因为本题中的元素值可以是负数。显然[a+1:b-1]这个范围内的所有负数元素都是不合算的，我们也应当将其移除。特别注意，如果a和b两处的花也是负数，我们却不能移除，因为我们约定要以该花为两端。所以这种方案的总价值是：[a+1:b-1]区间内的所有非负数之和，再加上a和b两处的元素。

如何求一个区间内的所有非负数之和呢？我们依然还是会用到前缀和的思想，但是处理的技巧是，在累加前缀和的时候，我们将所有的负数都变成0来处理。这样，用两处前缀和之差来计算区间和的时候，自动就忽略了所有的负数元素。