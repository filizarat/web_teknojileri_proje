<html>
<head>
	<meta charset="UTF-8">
	<title>MY BLOG</title>
	<link rel="stylesheet" href="css/bootstrap.min.css"/>
	<link rel="stylesheet" href="css/style.css"/>
	<script src="js/bootstrap.min.js"></script>
</head>
<header>
<div class="row">
			<div class="col-lg-12 col-md-12 col-sm-12">
			<input type="checkbox" id="res-menu">
			<label for="res-menu"><img src="img/iconnmenu.jpg"></label>
			<nav class="menu">  
				<ul>
					<li><a href="index.html">Ben Kimim?</a></li>
					<li><a href="egitim.html">Kariyer</a></li>
					<li><a href="sehrim.html">Şehrim</a></li>
					<li><a href="mirasımız.html">Mirasımız</a></li>
					<li><a href="iletisim.html">İletişim</a></li>
				</ul>
				<div class="clear"></div>
			</nav>
			</div>
			</div> 
			
</header>
<body>
<?php
 $_isim=$_POST['adi_soyadi'];
		  $_mesaj=$_POST['mesaj'];
		  echo('<br>');
				echo "Adınız: $_isim ";
				echo('<br>');
				echo "Mesajınız:  $_mesaj";
?>
</body>

</html>	