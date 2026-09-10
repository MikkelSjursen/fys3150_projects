import matplotlib.pyplot as plt

# Load data from file (column 0: x, column 1: u(x))
x, u = [], []
with open("data.txt", "r") as f:
    for line in f:
        cols = line.split()
        if cols:
            x.append(float(cols[0]))
            u.append(float(cols[1]))

# Plot exact solution
plt.figure(figsize=(8, 5))
plt.plot(x, u, label=r"$u(x) = 1 - (1 - e^{-10})x - e^{-10x}$", color="blue", linewidth=2)

plt.xlabel("x")
plt.ylabel("u(x)")
plt.title("Exact Solution u(x)")
plt.grid(True, linestyle="--", alpha=0.7)
plt.legend()

# Save plot image and display
plt.savefig("solution_plot.png", dpi=300)
plt.show()