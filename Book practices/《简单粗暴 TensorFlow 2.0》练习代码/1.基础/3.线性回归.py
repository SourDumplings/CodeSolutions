import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf

# 用线性模型 y = a * x + b 拟合数据

X_raw = np.array([2013, 2014, 2015, 2016, 2017], dtype=np.float32)
y_raw = np.array([12000, 14000, 15000, 16500, 17500], dtype=np.float32)

# 基本归一化
X = (X_raw - X_raw.min()) / (X_raw.max() - X_raw.min())
y = (y_raw - y_raw.min()) / (y_raw.max() - y_raw.min())

# 画出图形
plt.plot(X, y)
plt.show()

# 使用 numpy
# 输出结果 0.9763702027872221 0.057564988311377796
# a, b = 0, 0
#
# num_epoch = 10000
# learning_rate = 1e-3
# for e in range(num_epoch):
#   # 手动计算损失函数关于自变量（模型参数）的梯度
#   y_pred = a * X + b
#   grad_a, grad_b = (y_pred - y).dot(X), (y_pred - y).sum()
#
#   # 更新参数
#   a, b = a - learning_rate * grad_a, b - learning_rate * grad_b

# print(a, b)

# TensorFlow 下的线性回归
# 输出结果 <tf.Variable 'Variable:0' shape=() dtype=float32, numpy=0.97637> <tf.Variable 'Variable:0' shape=() dtype=float32, numpy=0.057565063>
X = tf.constant(X)
y = tf.constant(y)

a = tf.Variable(initial_value=0.)
b = tf.Variable(initial_value=0.)
variables = [a, b]

num_epoch = 10000
optimizer = tf.keras.optimizers.SGD(learning_rate=1e-3)
for e in range(num_epoch):
  # 使用tf.GradientTape()记录损失函数的梯度信息
  with tf.GradientTape() as tape:
    y_pred = a * X + b
    loss = 0.5 * tf.reduce_sum(tf.square(y_pred - y))
  # TensorFlow自动计算损失函数关于自变量（模型参数）的梯度
  grads = tape.gradient(loss, variables)
  # TensorFlow自动根据梯度更新参数
  optimizer.apply_gradients(grads_and_vars=zip(grads, variables))

print(a, b)
