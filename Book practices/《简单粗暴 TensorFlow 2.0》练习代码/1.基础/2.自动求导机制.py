import tensorflow as tf

# 计算函数 y = x^2 在 x = 3 处的导数
# x = tf.Variable(initial_value=3.)
# with tf.GradientTape() as tape:  # 在 tf.GradientTape() 的上下文内，所有计算步骤都会被记录以用于求导
#   y = tf.square(x)
# y_grad = tape.gradient(y, x)  # 计算y关于x的导数
# print([y, y_grad])

# 多元函数，对向量的求导
X = tf.constant([[1., 2.], [3., 4.]])
y = tf.constant([[1.], [2.]])
w = tf.Variable(initial_value=[[1.], [2.]])
b = tf.Variable(initial_value=1.)
temp0 = tf.matmul(X, w)
print(temp0)
temp1 = temp0 + b
print(temp1)
temp2 = temp1 - y
print(temp2)
temp3 = tf.square(temp2)
print(temp3)
temp4 = tf.reduce_sum(temp3)
print(temp4)
with tf.GradientTape() as tape:
    L = 0.5 * tf.reduce_sum(tf.square(tf.matmul(X, w) + b - y))
w_grad, b_grad = tape.gradient(L, [w, b])        # 计算L(w, b)关于w, b的偏导数
print([L.numpy(), w_grad.numpy(), b_grad.numpy()])
