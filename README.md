# simpleOpenGL3dGraph
OpenGL, taşınabilir, 2D ve 3D grafik uygulamaları geliştirmek için öncü bir sistemdir. 1992 yılından beri, endüstride 2D ve 3D desteği olan ve kullanılan program arayüzü olup çok geniş bir bilgisayar ağına hizmet etmektedir. OPENGL, özel efektlerle, güçlü görsel fonksiyonlarla, haritalama için hızlı uygulama geliştirme sağlar.

Bu projede de OpenGL 3D özelliklerinden faydalanıldı.

# Projenin Çalıştırılması
Projeyi çalıştırmak için ortam olarak Visual Studio programını edinmemiz gerekiyor. Daha sonra dışardan indirerek eklememiz gereken <strong><i>GLU/GLUT</i></strong> kütüphaneleri var. Onlara [bu linkten](http://www.mediafire.com/file/cmlnr0pj0pyha5d/Glew_and_Glut.zip/file) ulaşabilirsiniz. Dosyayı indirdikten sonra ilk olarak dosya içindeki ".dll" uzantılı belgeleri <i>C:\Windows\System32</i> dosya yolundaki klasörün içine kopyalayıp yapıştırmamız gerekli.

Ardından projeyi Visual Studio ile başlattıktan sonra sağ tarafta bulunan kısımda projenin üzerine sağ tıklayarak <strong>Özellikler</strong> kısmına giriyoruz.

![](https://github.com/shrgrl/simpleOpenGL3dGraph/blob/master/img.jpg)

Burada karşımıza çıkan ekranda C/C++ seçeneğinin <strong>Genel</strong> kısmındaki <strong>Ek İçeren Dizinler</strong> seçeneğine girip, indirdiğimiz dosya dizininin içinden ayrı ayrı <strong>include</strong> dosyalarını ekliyoruz.

![](https://github.com/shrgrl/simpleOpenGL3dGraph/blob/master/img1.jpg)

İkinci olarak <strong>Bağlayıcı</strong> kısmındaki <strong>Ek Kitaplık Dizinleri</strong> seçeneğine girip, indirdiğimiz dosya dizininin içinden ayrı ayrı <strong>lib</strong> dosyalarını ekliyoruz.

![](https://github.com/shrgrl/simpleOpenGL3dGraph/blob/master/img2.jpg)

Bütün ekleme işlemlerinin ardından projemizi çalıştırabiliriz. Run tuşuna bastıktan sonra karşımıza çıkan arayüzde beliren graphımızı, fare ve klavye ile kontrol ederek hareket ve konumlarını değiştirebiliriz. 

![](https://github.com/shrgrl/simpleOpenGL3dGraph/blob/master/img3.jpg) 
![](https://github.com/shrgrl/simpleOpenGL3dGraph/blob/master/img4.jpg) 
![](https://github.com/shrgrl/simpleOpenGL3dGraph/blob/master/img5.jpg)
