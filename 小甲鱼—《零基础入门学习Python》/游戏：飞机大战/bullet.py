# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: bullet.py
@time: 2017/8/13 16:46

子弹模块
"""

import pygame

class Bullet1(pygame.sprite.Sprite):
    def __init__(self, position):
        pygame.sprite.Sprite.__init__(self)

        self.image = pygame.image.load('images/bullet1.png').convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.left, self.rect.top = position
        self.speed = 12
        self.active = False
        self.mask = pygame.mask.from_surface(self.image)

    def move(self):
        self.rect.top -= self.speed

        if self.rect.top < 0:
            self.active = False

    def reset(self, position):
        self.rect.left, self.rect.top = position
        self.active = True


class Bullet2(pygame.sprite.Sprite):
    def __init__(self, position):
        pygame.sprite.Sprite.__init__(self)

        self.image = pygame.image.load('images/bullet2.png').convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.left, self.rect.top = position
        self.speed = 14
        self.active = False
        self.mask = pygame.mask.from_surface(self.image)

    def move(self):
        self.rect.top -= self.speed

        if self.rect.top < 0:
            self.active = False

    def reset(self, position):
        self.rect.left, self.rect.top = position
        self.active = True


def main():
    pass


if __name__ == '__main__':
    main()
