# LiarExtractor
Liar is a 2 player game that works like this:
1. Choose a category of things
2. Start a bid: the first player must state how many objects of the category he can nominate in 1 minute. The other player can raise the bid, and so on.
3. When one of the player says "Liar", the other one must now name as many objects of the choosen category as in the last bid.
4. If he can do that, he wins the round, else the opponent wins.

This simple project helps with the extraction of the categories.

In the file `categories/categorie.txt` the players can add new categories, which will be extracted (one per line).

It is possible to use the notation `category <subcategory>` to increase the variability in the present categories. There must be a file named `categories/subcategory.txt`.

For example: `Actors from <nation>` and a file named `categories/nation.txt`.
