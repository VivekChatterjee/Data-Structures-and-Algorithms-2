<h2><a href="https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card">Level Order in spiral form</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" bis_skin_checked="1"><p><span style="font-size: 14pt;">Given a binary tree and the task is to find the spiral order traversal of the tree and return the list containing the elements.<br><strong style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Spiral order Traversal mean:</strong><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;"> Starting from level 0 for root node, for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right.</span><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;"> <br></span><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">For below tree, function should return [1, 2, 3, 4, 5, 6, 7]</span></span></p>
<p><span style="font-size: 14pt;"><strong>&nbsp;</strong></span><img src="https://www.geeksforgeeks.org/wp-content/uploads/2009/12/spiral_order.gif" alt="spiral_order" width="386" height="207"></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>root = [1, 3, 2]
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1
 &nbsp;&nbsp; /&nbsp;&nbsp; \
 &nbsp;&nbsp;3&nbsp;&nbsp;&nbsp;&nbsp; 2
<strong>Output: </strong>[1, 3, 2]<br><strong>Explanation</strong>: Start with root (1), print level 0 (right to left), then level 1 (left to right).</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>root = [10, 20, 30, 40, 60]<strong><br></strong>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 10
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;&nbsp;&nbsp; \
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 20&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;30
 &nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;&nbsp; \
 &nbsp;&nbsp; 40&nbsp;&nbsp;&nbsp;&nbsp; 60
<strong>Output: </strong>[10, 20, 30, 60, 40]<br><strong>Explanation</strong>: Start with root (10), print level 0 (right to left), level 1 (left to right), and continue alternating.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>root = [1, 2, N, 4]
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;&nbsp;&nbsp; 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 2&nbsp;&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;&nbsp;
 &nbsp;&nbsp; 4&nbsp;&nbsp;&nbsp;&nbsp; 
<strong>Output: </strong>[1, 2, 4]<br><strong>Explanation</strong>: Start with root (1), then level 1 (left to right), then level 2 (right to left).</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 &lt;= number of nodes &lt;= 10<sup>5</sup><br>0 &lt;= node-&gt;data &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Morgan Stanley</code>&nbsp;<code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Hike</code>&nbsp;<code>Housing.com</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Ola Cabs</code>&nbsp;<code>Payu</code>&nbsp;<code>Teradata</code>&nbsp;<code>Walmart</code>&nbsp;<code>Adobe</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Recursion</code>&nbsp;<code>Stack</code>&nbsp;<code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;