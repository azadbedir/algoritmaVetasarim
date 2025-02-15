# Toplu Taşıma Güzergah Planlama

Bu proje, bir şehrin üç farklı mahallesinde yeni bir toplu taşıma hattı planlamasını yapmayı amaçlamaktadır. Değerlendirme kriterleri aşağıdaki gibi belirlenmiştir:

- **Nüfus Yoğunluğu**
- **Mevcut Ulaşım Altyapısı**
- **Maliyet Analizi**
- **Çevresel Etki**
- **Sosyal Fayda**

Bu kriterlere belirli ağırlıklar atanarak, en uygun mahalle **Softmax algoritması** kullanılarak belirlenir.

---

## 🚀 Kullanım Talimatları

1. **Proje dosyasını derleyin:**
   ```sh
   gcc -o toplu_tasima toplu_tasima.c -lm
   ```
2. **Programı çalıştırın:**
   ```sh
   ./toplu_tasima
   ```
3. **Mahalleler için kriterleri girin:**
   - Nüfus Yoğunluğu (0-1 arası)
   - Mevcut Ulaşım Altyapısı (0-1 arası)
   - Maliyet (0-1 arası)
   - Çevresel Etki (0-1 arası)
   - Sosyal Fayda (0-1 arası)

4. **Sonuçlar ekranda görüntülenir:**
   - Mahallelerin **Softmax puanları**
   - En uygun mahalle **seçimi**

---

## 📌 Kodun İçeriği

### **1️⃣ Softmax Hesaplama Fonksiyonu**
Bu fonksiyon mahallelerin toplam puanlarını normalleştirerek **Softmax değerlerini** hesaplar.

### **2️⃣ Ana Fonksiyon (main)**
- Kullanıcıdan **kriter değerlerini** alır.
- Her mahalle için **toplam puan hesaplar**.
- **Softmax fonksiyonunu** çağırarak mahalleleri karşılaştırır.
- **En uygun mahalleyi belirler ve ekrana yazdırır.**

---

## 📊 Örnek Çıktı

```sh
İstasyon Mahallesi için kriterleri girin (Nüfus Yoğunluğu, Ulaşım Altyapısı, Maliyet, Çevresel Etki, Sosyal Fayda):
0.8 0.7 0.5 0.6 0.9

Demirtaş Mahallesi için kriterleri girin:
0.6 0.8 0.7 0.5 0.8

Karahıdır Mahallesi için kriterleri girin:
0.9 0.6 0.4 0.7 0.7

Mahallelerin Softmax Puanları:
İstasyon Mahallesi: 0.4012
Demirtaş Mahallesi: 0.3104
Karahıdır Mahallesi: 0.2884

En uygun güzergah: İstasyon Mahallesi
```

---

## 🔧 Geliştirme
- Kriter ağırlıklarını **kullanıcı girişine** bağlı hale getirebilirsiniz.
- Daha fazla mahalle ekleyerek genişletilebilir.
- GUI eklenerek görselleştirilebilir.

---

## 📜 Lisans
Bu proje MIT Lisansı altında kullanıma sunulmuştur.
Serbestçe geliştirebilir ve kullanabilirsiniz. 😊

