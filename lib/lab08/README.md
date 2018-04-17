# Lab 8: Hashing and Sorting #
This lab focuses on two separate topics, the first being hashing and the second being sorting. Up until now, you have been doing exhaustive searching, where you have had to go to every item in your data structure in order to find something you were looking for. Well there is a better way to do random access. You can instead use a data structure called a hash table, that stores objects in an array, but places them in the array based on the output of a function. 

You will also be implementing two very important sorting functions this week. Bubble sort, insertion sort, and selection sort are not the most efficient sorting algorithm around, with all of those having a running time of n^2. We want something that goes quite a bit faster. Some very smart people decades ago found some great algorithms. You will be implementing two of them; quicksort and merge sort. Both of these will be using your `doubly_linked_list` from lab 6, so make sure that that is fully working.

### Lab Instructions ###

Implement the hash table using the three most common probing techniques: linear, quadratic, double. Use the two provided hashing functions `hash_1` and `hash_2`. Refer to the function definition comments for more information on each of the functions.

Implement both merge sort and quicksort. Verify they sort. We will only provide basic tests. *You* must implement the sorts using their algorithms.

There are thousands of videos on YouTube that cover these topics in much more depth than we will have the opportunity during class. Use them for more help understanding the assignment. If you find one that helped you, post it in the Lab 8 channel on slack to help your fellow classmates out.

### Hash Table Information ###
* Wikipedia article on [Hash Function](https://en.wikipedia.org/wiki/Hash_function)
* Wikipedia article on [Hash Table](https://en.wikipedia.org/wiki/Hash_table)
* Youtube video on [Hash Table](https://www.youtube.com/watch?v=shs0KM3wKv8)

### Quicksort Information ###
* Wikipedia article on [Quicksort](https://en.wikipedia.org/wiki/Quicksort)
* Youtube video on [Quick Sort](https://www.youtube.com/watch?v=SLauY6PpjW4)

### Merge Sort Information ###
* Wikipedia article on [Merge sort](https://en.wikipedia.org/wiki/Merge_sort)
* Youtube explanation of [Merge sort](https://youtu.be/KF2j-9iSf4Q)
* Explanation of a [Hash function](http://www.partow.net/programming/hashfunctions/)