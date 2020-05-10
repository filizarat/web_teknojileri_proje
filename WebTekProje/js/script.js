function temizlee() {
    document.getElementById("form").reset();
}
function sonuc() {
    var adi_soyadi = document.forms["form"]["adi_soyadi"].value;

    if (adi_soyadi == "" || adi_soyadi == null) {
        alert("Ad Soyad Alanını Boş Bıraktınız!");
        document.forms["form"]["adi_soyadi"].focus();
        return false;
    }
    if (!form.chooseone[0].checked && !form.chooseone[1].checked) {
        alert("Cinsiyet  Alanını Boş Bıraktınız!");
        return false;
    }

    var mail = document.forms["form"]["mail"].value;
    var atpos = mail.indexOf("@");
    var dotpos = mail.lastIndexOf(".");
    if (atpos < 1 || dotpos < atpos + 2 || dotpos + 2 >= mail.length) {
        alert("Geçerli email adresi girin");
        document.forms["form"]["mail"].focus();
        return false;
    }
    var telefon = document.forms["form"]["telefon"].value;

    if (telefon == "" || telefon == null) {
        alert("Telefon Numarası Alanını Boş Bıraktınız!");
        document.forms["form"]["telefon"].focus();
        return false;
    }
    var mesaj = document.forms["form"]["mesaj"].value;

    if (mesaj == "" || mesaj == null) {
        alert("Mesaj Alanını Boş Bıraktınız!");
        document.forms["form"]["mesaj"].focus();
        return false;
    }
    else {
        
    }
    
}
function Sayi(e) {
        islem = document.all ? window.event : e;
        karakter = document.all ? islem.keyCode : islem.which;
        if (karakter < 48 || karakter > 57) {
            if (document.all) {
                islem.returnValue = false;
            }
            else {
                islem.preventDefault();
            }
        }

    }
    function Harf(e) {
        islem = document.all ? window.event : e;
        karakter = document.all ? islem.keyCode : islem.which;
        if (karakter >= 48 && karakter <= 57) {
            if (document.all) {
                islem.returnValue = false;
            }
            else {
                islem.preventDefault();
            }

        }

    }

    $(document).ready(function () {
        var slider = 0;
        $('.sliderbutton li:first').css('background', 'white');
        var lenghtli = $('#slider li').length;

        var interval = setInterval('$.slider(' + lenghtli + ')', 3000);
        $.slider = function (toplam) {

            $('#slider li').hide();
            var lenghtli = $('#slider li').length;

            if (slider < toplam - 1) {
                slider++;
                $('.sliderbutton li').css('background', 'red');
                $('.sliderbutton li:eq(' + slider + ')').css('background', 'white');
                $('#slider li:eq(' + slider + ')').fadeIn("fast");
            }
            else {
                $('#slider li:first').fadeIn("fast");
                slider = 0;
                $('.sliderbutton li').css('background', 'red');
                $('.sliderbutton li:eq(' + slider + ')').css('background', 'white');
            }
        };
        $('.sliderleft').click(function () {
            slider--;
            $('.sliderbutton li').css('background', 'red');
            if (slider < 0) {
                $('.sliderbutton li:last').css('background', 'white');
                slider = lenghtli - 1;
            } else {
                $('.sliderbutton li:eq(' + slider + ')').css('background', 'white');
            }
            $('#slider li').hide();
            $('#slider li:eq(' + slider + ')').fadeIn("fast");
        });
        $('.sliderright').click(function () {
            slider++;
            $('.sliderbutton li').css('background', 'red');
            if (slider > lenghtli - 1) {
                $('.sliderbutton li:first').css('background', 'white');
                slider = 0;
            } else {
                $('.sliderbutton li:eq(' + slider + ')').css('background', 'white');
            }
            $('#slider li').hide();
            $('#slider li:eq(' + slider + ')').fadeIn("fast");
        });
        $('.sliderbutton li').click(function () {
            $('.sliderbutton li').css('background', 'red');
            $(this).css('background', 'white');
            interval = clearInterval(interval);
            var indis = $(this).index();
            $('#slider li').hide();
            $('#slider li:eq(' + indis + ')').fadeIn("fast");
            slider = indis;
            interval = setInterval('$.slider(' + lenghtli + ')', 3000);
        });
        $('#slider').hover(function () {
            interval = clearInterval(interval);
        }, function () {
            interval = setInterval('$.slider(' + lenghtli + ')', 3000);
        })
    });