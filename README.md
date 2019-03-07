<p style="margin-bottom: 12.0pt; background: white;"><strong><span style="font-family: 'Segoe UI',sans-serif; color: #24292e;">ULUSAL HAVA YOLU ACENTASI</span></strong></p>
<p style="background: white; box-sizing: border-box; font-variant-ligatures: normal; font-variant-caps: normal; orphans: 2; text-align: start; widows: 2; -webkit-text-stroke-width: 0px; text-decoration-style: initial; text-decoration-color: initial; word-spacing: 0px; margin: 0cm 0cm 12.0pt 0cm;"><strong style="box-sizing: border-box;"><span style="box-sizing: border-box;"><span style="font-family: 'Segoe UI',sans-serif; color: #24292e;">&Ouml;zet:</span></span></strong></p>
<p style="margin: 0cm; margin-bottom: .0001pt; background: white; box-sizing: border-box; font-variant-ligatures: normal; font-variant-caps: normal; orphans: 2; text-align: start; widows: 2; -webkit-text-stroke-width: 0px; text-decoration-style: initial; text-decoration-color: initial; word-spacing: 0px;"><span style="box-sizing: border-box;"><em style="box-sizing: border-box;"><span style="font-size: 11.0pt; font-family: 'Calibri Light',sans-serif; color: #24292e;">Proje C++ dili ve veritabanı y&ouml;netim sistemi i&ccedil;in de MYSQL kullanılarak geliştirilmiştir.</span></em></span></p>
<p style="margin: 0cm; margin-bottom: .0001pt; background: white;"><em><span style="font-size: 11.0pt; font-family: 'Calibri Light',sans-serif; color: #24292e;">Veritabanında veriler aşağıdaki şekilde tablolarda tutulmaktadır.</span></em></p>
<p style="margin-bottom: .0001pt; text-indent: 35.4pt;"><em><span style="font-family: 'Calibri Light',sans-serif;">*Yolcular(<u>TCKN</u>, ISIM, EPOSTA, PLAKAKOD,&nbsp; ADRES)</span></em></p>
<p style="margin-bottom: .0001pt; text-indent: 35.4pt;"><em><span style="font-family: 'Calibri Light',sans-serif;">*Ucak(<u>UKN</u>, MODEL, KAPASITE)</span></em></p>
<p style="margin-bottom: .0001pt; text-indent: 35.4pt;"><em><span style="font-family: 'Calibri Light',sans-serif;">*Sefer(<u>UKN</u>, <u>TARIH</u>, SAAT, BAS_NOKTA, BIN_NOKTA)</span></em></p>
<p style="margin-bottom: .0001pt; text-indent: 35.4pt;"><em><span style="font-family: 'Calibri Light',sans-serif;">*Yolculuk(TCKN,UKN, TARIH)</span></em></p>
<p style="margin-bottom: .0001pt;"><em><span style="font-family: 'Calibri Light',sans-serif;">Ayrıca projede veritabını i&ccedil;in yeni sefer tanımlama, bilet satma, yolcu sorgulama, u&ccedil;uş iptali, bilet iptali, sefer sorgulama, doluluk oranı en fazla olan u&ccedil;uşların listelenmesi gibi işlemlere yer verilmiştir. Bu işlemler yapılırken tanımlı olmayan u&ccedil;ak i&ccedil;in sefer bilgisi, tanımlı olmayan yolcu i&ccedil;in u&ccedil;uş bilgisi oluşturulamamaktadır. Eğer u&ccedil;ak kapasitesi yeterli değilse bilet satışının da yapılamayacağı belirtilmektedir.</span></em></p>
<p style="background: white; margin: 0cm 0cm 12.0pt 0cm;"><strong><span style="font-family: 'Segoe UI',sans-serif; color: #24292e;">Create Table C&uuml;mleleri(Sql):</span></strong></p>
<table style="border-collapse: collapse; width: 100%;" border="1">
<tbody>
<tr>
<td style="width: 100%;">
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">DROP DATABASE IF EXISTS havayolu;</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">CREATE DATABASE havayolu;</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">USE havayolu;</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">CREATE TABLE Yolcular(</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; TCKN varchar(11),</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ISIM varchar(50),</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; EPOSTA varchar(50),</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; PLAKAKOD int,</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ADRES varchar(100),</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; PRIMARY KEY (TCKN)</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">);</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">CREATE TABLE Ucak(</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; UKN varchar(11),</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; MODEL varchar(50),</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; KAPASITE int,</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; PRIMARY KEY (UKN)</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">);</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">CREATE TABLE Sefer(</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; UKN varchar(11),</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; TARIH varchar(8),</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; SAAT varchar(4),</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; BAS_NOKTA int,</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; BIT_NOKTA int,</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; PRIMARY KEY (UKN, TARIH),</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp; FOREIGN KEY (UKN) REFERENCES Ucak(UKN)</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">);</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">CREATE TABLE Yolculuk(</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; TCKN varchar(11),</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; UKN varchar(11),</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; TARIH varchar(8),</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp; FOREIGN KEY (TCKN) REFERENCES Yolcular(TCKN),</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp; FOREIGN KEY (UKN, TARIH) REFERENCES Sefer(UKN, TARIH)</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">);</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">CREATE VIEW havayolu.sefer_bilet AS</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp; (SELECT </span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; s.UKN,</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; s.TARIH,</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; s.SAAT,</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; s.BAS_NOKTA,</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; s.BIT_NOKTA,</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; u.KAPASITE,</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; COUNT(b.TCKN) AS DOLU,</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; u.KAPASITE - COUNT(b.TCKN) AS BOS,</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 100 * COUNT(b.TCKN) / u.KAPASITE AS DOLULUK</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp; FROM</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;havayolu.Sefer s</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp; INNER JOIN havayolu.Ucak u ON s.UKN = u.UKN</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp; LEFT JOIN havayolu.yolculuk b ON s.UKN = b.UKN AND s.TARIH = b.TARIH</span></p>
<p style="text-indent: 35.4pt;"><span style="font-size: 8.0pt; line-height: 107%;">&nbsp;&nbsp;&nbsp; GROUP BY s.UKN , s.TARIH , s.SAAT , s.BAS_NOKTA , s.BIT_NOKTA , u.KAPASITE);</span></p>
</td>
</tr>
</tbody>
</table>
<p style="background: white; margin: 0cm 0cm 12.0pt 0cm;"><strong><span style="font-family: 'Segoe UI',sans-serif; color: #24292e;">Genel Yapı:</span></strong></p>
<p style="box-sizing: border-box; font-variant-ligatures: normal; font-variant-caps: normal; orphans: 2; text-align: start; widows: 2; -webkit-text-stroke-width: 0px; text-decoration-style: initial; text-decoration-color: initial; word-spacing: 0px;"><span style="box-sizing: border-box;"><span style="font-size: 9.0pt; line-height: 107%;">C++ dili ve veritabanı y&ouml;netim sistemi i&ccedil;in de MYSQL kullanılarak ulusal bir havayolu acentası i&ccedil;in bir consol uygulaması geliştirilmiştir.</span></span></p>
<p><span style="font-size: 9.0pt; line-height: 107%;">İşlem listesi; u&ccedil;ak işlemleri, sefer işlemleri, yolcu işlemleri, bilet işlemleri ve &ccedil;ıkıştan oluşmakta olup men&uuml; şeklinde kullanıcıya sunulmakta ve işlemlerin ger&ccedil;ekleştirilmesi i&ccedil;in ilgili b&ouml;l&uuml;mlere aşağıdaki şekilde y&ouml;nlendirilmektedir.</span></p>
<p><span style="font-size: 9.0pt; line-height: 107%;">İşlem listesinden 1 yani u&ccedil;ak işlemleri se&ccedil;ildiğinde kullanıcı u&ccedil;ak işlem listesine y&ouml;nlendiriliyor.</span></p>
<p style="margin-left: 35.4pt;"><span style="font-size: 9.0pt; line-height: 107%;">Kullanıcı u&ccedil;ak işlem listesinde 1 girerek u&ccedil;ak listesini getirebilir, 2 girerek yeni u&ccedil;ak tanımlayabilir, 3 girerek u&ccedil;ak bilgilerini silebilir, 4 girerek u&ccedil;ak bilgilerini g&uuml;ncelleyebilir ve 0 girerekte bir &ouml;nceki men&uuml;ye geri d&ouml;nebilir.</span></p>
<p><span style="font-size: 9.0pt; line-height: 107%;">İşlem listesinden 3 yani yolcu işlem listesi se&ccedil;ildiğinde kullanıcı yolcu işlem listesine y&ouml;nlendiriliyor.</span></p>
<p style="margin-left: 35.4pt;"><span style="font-size: 9.0pt; line-height: 107%;">Kullanıcı yolcu işlem listesinde 1 girerek tanımlı&nbsp; yolcu listesini getirebilir, 2 girerek yeni yolcu tanımlayabilir, 3 girerek yolcu bilgilerini silebilir, ve 0 girerekte bir &ouml;nceki men&uuml;ye geri d&ouml;nebilir.</span></p>
<p><span style="font-size: 9.0pt; line-height: 107%;">İşlem listesinden 2 yani sefer işlemleri se&ccedil;ildiğinde kullanıcı sefer işlem listesine y&ouml;nlendiriliyor.</span></p>
<p style="margin-left: 35.4pt;"><span style="font-size: 9.0pt; line-height: 107%;">Kullanıcı sefer işlem listesinde 1 girerek sefer listesini getirebilir, 2 girerek sefer yolcu listesini getirebilir, 3 girerek yeni sefer tanımlayabilir, 4 girerek sefer iptal edebilir ve 0 girerekte bir &ouml;nceki men&uuml;ye geri d&ouml;nebilir.</span></p>
<p><span style="font-size: 9.0pt; line-height: 107%;">İşlem listesinden 4 yani bilet işlemleri se&ccedil;ildiğinde kullanıcı bilet işlem listesine y&ouml;nlendiriliyor.</span></p>
<p style="margin-left: 35.4pt;"><span style="font-size: 9.0pt; line-height: 107%;">Kullanıcı bilet işlem listesinde 1 girerek bilet satın ama, 2 girerek bilet iptal etme, 3 girerek yolcu bilet sorgulma ve 0 girerekte bir &ouml;nceki men&uuml;ye geri d&ouml;nebilir.</span></p>
<p><span style="font-size: 9.0pt; line-height: 107%;">İşlem listesinden 0 yani &ccedil;ıkış işlemi se&ccedil;ildiğinde kullanıcı programı sonlandırmış olur.</span></p>
<p><span style="font-size: 9.0pt; line-height: 107%;">&nbsp;</span></p>
<p><span style="font-size: 9.0pt; line-height: 107%;">&nbsp;</span></p>
<p><span style="font-size: 9.0pt; line-height: 107%;">&nbsp;</span></p>
<p><span style="font-size: 9.0pt; line-height: 107%;">&nbsp;</span></p>
<p><span style="font-size: 9.0pt; line-height: 107%;">&nbsp;</span></p>
<p><span style="font-size: 9.0pt; line-height: 107%;">&nbsp;</span></p>
<p><span style="font-size: 9.0pt; line-height: 107%;">&nbsp;</span></p>
<p style="background: white; margin: 0cm 0cm 12.0pt 0cm;">&nbsp;</p>
