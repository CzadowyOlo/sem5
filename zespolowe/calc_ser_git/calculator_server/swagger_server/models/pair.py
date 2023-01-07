# coding: utf-8

from __future__ import absolute_import
from datetime import date, datetime  # noqa: F401

from typing import List, Dict  # noqa: F401

from swagger_server.models.base_model_ import Model
from swagger_server import util


class Pair(Model):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """
    def __init__(self, number1: int=None, number2: int=None):  # noqa: E501
        """Pair - a model defined in Swagger

        :param number1: The number1 of this Pair.  # noqa: E501
        :type number1: int
        :param number2: The number2 of this Pair.  # noqa: E501
        :type number2: int
        """
        self.swagger_types = {
            'number1': int,
            'number2': int
        }

        self.attribute_map = {
            'number1': 'number1',
            'number2': 'number2'
        }
        self._number1 = number1
        self._number2 = number2

    @classmethod
    def from_dict(cls, dikt) -> 'Pair':
        """Returns the dict as a model

        :param dikt: A dict.
        :type: dict
        :return: The Pair of this Pair.  # noqa: E501
        :rtype: Pair
        """
        return util.deserialize_model(dikt, cls)

    @property
    def number1(self) -> int:
        """Gets the number1 of this Pair.


        :return: The number1 of this Pair.
        :rtype: int
        """
        return self._number1

    @number1.setter
    def number1(self, number1: int):
        """Sets the number1 of this Pair.


        :param number1: The number1 of this Pair.
        :type number1: int
        """

        self._number1 = number1

    @property
    def number2(self) -> int:
        """Gets the number2 of this Pair.


        :return: The number2 of this Pair.
        :rtype: int
        """
        return self._number2

    @number2.setter
    def number2(self, number2: int):
        """Sets the number2 of this Pair.


        :param number2: The number2 of this Pair.
        :type number2: int
        """

        self._number2 = number2