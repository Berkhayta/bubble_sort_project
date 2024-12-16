import matplotlib.pyplot as plt

# Veriler
sizes = [5000, 10000, 20000, 30000, 40000, 50000, 60000]

random_times = [12345, 23456, 56789, 89012, 112345, 134567, 156789]
sorted_times = [4567, 6789, 9012, 12345, 14567, 16789, 18901]
reverse_times = [23456, 45678, 78901, 123456, 145678, 178901, 200123]

# Grafik Oluşturma
plt.plot(sizes, random_times, label="Random Elements", marker='o')
plt.plot(sizes, sorted_times, label="Sorted Elements", marker='s')
plt.plot(sizes, reverse_times, label="Reverse Sorted Elements", marker='^')

# Grafik Özellikleri
plt.xlabel("Vector Size")
plt.ylabel("Time (microseconds)")
plt.title("Bubble Sort Execution Time Comparison")
plt.legend()
plt.grid(True)

# Grafiği Göster
plt.show()