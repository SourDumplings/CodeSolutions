# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: myplane.py
@time: 2017/8/11 15:57

飞机大战：我方飞机
"""

import pygame

class MyPlane(pygame.sprite.Sprite):
    def __init__(self, bg_size):
        pygame.sprite.Sprite.__init__(self)

        self.image1 = pygame.image.load('images/me1.png').convert_alpha()
        self.image2 = pygame.image.load('images/me2.png').convert_alpha()
        self.destroy_images = []
        self.destroy_images.extend([\
            pygame.image.load('images/me_destroy_1.png').convert_alpha(), \
            pygame.image.load('images/me_destroy_2.png').convert_alpha(), \
            pygame.image.load('images/me_destroy_3.png').convert_alpha(), \
            pygame.image.load('images/me_destroy_4.png').convert_alpha()])
        self.rect = self.image1.get_rect()
        self.width, self.height = bg_size[0], bg_size[1]
        self.rect.left, self.rect.top = \
            (self.width - self.rect.width) // 2, \
            (self.height - self.rect.height - 60)
        self.speed = 10
        self.active = True
        self.mask = pygame.mask.from_surface(self.image1)
        self.invincible = False

    def moveUp(self):
        if self.rect.top > 0:
            self.rect.top -= self.speed
        else:
            self.rect.top = 0

    def moveDown(self):
        if self.rect.bottom < self.height - 60:
            self.rect.top += self.speed
        else:
            self.rect.bottom = self.height - 60

    def moveLeft(self):
        if self.rect.left > 0:
            self.rect.left -= self.speed
        else:
            self.rect.left = 0

    def moveRight(self):
        if self.rect.right < self.width:
            self.rect.left += self.speed
        else:
            self.rect.right = self.width

    def reset(self):
        self.rect.left, self.rect.top = \
            (self.width - self.rect.width) // 2, \
            (self.height - self.rect.height - 60)
        self.active = True
        self.invincible = True


def main():
    pass


if __name__ == '__main__':
    main()