​base case=>

- if only on item is there in vector
- if 2 items on the vector

Fn = f(n-1) +k

if there are more items

F(n-1) will give me min cost if i choose this path
F(n-2) will give me mincost if i choose this path

note both of these path do not include their cost of the selected stair

so it is actually giving us the cost of items after that stair

so we will have to add the cost of the selected stair itsled
