<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>Keywords - Plange</title>
		<link rel=StyleSheet href='../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../header.php') ?>
		<p>The keywords listing is provided for reference. Here, "keyword" is used loosely. For example, the "abstract" keyword is implemented as a function in the standard library and has no special meaning. Nonetheless, it is listed as a keyword because it represents a language feature. On the other hand, keywords like "do" have definitions that are present in the syntax of the language but again represent a language feature. This is the guiding rule for selection of keywords.</p>

		<h2>Reserved Keywords</h2>
		<p>Syntactically, there are no reserved keywords. For instance, "if" can be used like a variable.</p>
		<div class="code2">
			<p>Example</p>
			<pre>
if := (&lt;Bool&gt; condition, &lt;Void -&gt; T&gt; t, &lt;Void -&gt; T&gt; f) {
	return (condition ? t : f)();
};
			</pre>
		</div>

		<p>The <code>if</code> keyword only has special meaning in the correct syntactic context.</p>
		<h2>Subpage Listing</h2>
		<ul>
			<li><a href="/documentation/keywords/dont_care.php">_ (dont_care)</a></li>
			<li><a href="/documentation/keywords/abstract.php">abstract</a></li>
			<li><a href="/documentation/keywords/address_of.php">address_of</a></li>
			<li><a href="/documentation/keywords/alloc.php">alloc</a></li>
			<li>apply</li>
			<li>arguments</li>
			<li><a href="/documentation/keywords/asm.php">asm</a></li>
			<li><a href="/documentation/keywords/atomic.php">atomic</a></li>
			<li><a href="/documentation/keywords/break.php">break</a></li>
			<li>caller</li>
			<li><a href="/documentation/keywords/casts.php">casts</a></li>
			<li><a href="/documentation/keywords/catch.php">catch</a></li>
			<li><a href="/documentation/keywords/context.php">context</a></li>
			<li><a href="/documentation/keywords/continue.php">continue</a></li>
			<li><a href="/documentation/keywords/dereference.php">dereference</a></li>
			<li><a href="/documentation/keywords/do.php">do</a></li>
			<li><a href="/documentation/keywords/dynamic_cast.php">dynamic_cast</a></li>
			<li><a href="/documentation/keywords/elif.php">elif</a></li>
			<li><a href="/documentation/keywords/else.php">else</a></li>
			<li><a href="/documentation/keywords/enum.php">enum</a></li>
			<li><a href="/documentation/keywords/env.php">env</a></li>
			<li><a href="/documentation/keywords/finally.php">finally</a></li>
			<li><a href="/documentation/keywords/for.php">for</a></li>
			<li><a href="/documentation/keywords/free.php">free</a></li>
			<li><a href="/documentation/keywords/get.php">get</a></li>
			<li><a href="/documentation/keywords/if.php">if</a></li>
			<li><a href="/documentation/keywords/imperative.php">imperative</a></li>
			<li><a href="/documentation/keywords/implementing.php">implementing</a></li>
			<li><a href="/documentation/keywords/inheriting.php">inheriting</a></li>
			<li><a href="/documentation/keywords/internal.php">internal</a></li>
			<li><a href="/documentation/keywords/is.php">is</a></li>
			<li><a href="/documentation/keywords/no_throw.php">no_throw</a></li>
			<li><a href="/documentation/keywords/opaque.php">opaque</a></li>
			<li><a href="/documentation/keywords/params.php">params</a></li>
			<li><a href="/documentation/keywords/private.php">private</a></li>
			<li><a href="/documentation/keywords/protected.php">protected</a></li>
			<li><a href="/documentation/keywords/protected_internal.php">protected_internal</a></li>
			<li><a href="/documentation/keywords/public.php">public</a></li>
			<li><a href="/documentation/keywords/pure.php">pure</a></li>
			<li><a href="/documentation/keywords/reinterpret_cast.php">reinterpret_cast</a></li>
			<li><a href="/documentation/keywords/return.php">return</a></li>
			<li><a href="/documentation/keywords/set.php">set</a></li>
			<li><a href="/documentation/keywords/stable.php">stable</a></li>
			<li><a href="/documentation/keywords/static.php">static</a></li>
			<li><a href="/documentation/keywords/this.php">this</a></li>
			<li><a href="/documentation/keywords/this_type.php">this_type</a></li>
			<li><a href="/documentation/keywords/try.php">try</a></li>
			<li><a href="/documentation/keywords/type.php">type</a></li>
			<li><a href="/documentation/keywords/type_of.php">type_of</a></li>
			<li>unit</li>
			<li><a href="/documentation/keywords/unstable.php">unstable</a></li>
			<li><a href="/documentation/keywords/until.php">until</a></li>
			<li><a href="/documentation/keywords/volatile.php">volatile</a></li>
		</ul>

		<?php require('../footer.php') ?>
	</body>
</html>