# coding: utf-8

from __future__ import absolute_import
from datetime import date, datetime  # noqa: F401

from typing import List, Dict  # noqa: F401

from swagger_server.models.base_model_ import Model
from swagger_server.models.address import Address  # noqa: F401,E501
from swagger_server import util


class Customer(Model):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """
    def __init__(self, id: int=None, username: str=None, address: List[Address]=None):  # noqa: E501
        """Customer - a model defined in Swagger

        :param id: The id of this Customer.  # noqa: E501
        :type id: int
        :param username: The username of this Customer.  # noqa: E501
        :type username: str
        :param address: The address of this Customer.  # noqa: E501
        :type address: List[Address]
        """
        self.swagger_types = {
            'id': int,
            'username': str,
            'address': List[Address]
        }

        self.attribute_map = {
            'id': 'id',
            'username': 'username',
            'address': 'address'
        }
        self._id = id
        self._username = username
        self._address = address

    @classmethod
    def from_dict(cls, dikt) -> 'Customer':
        """Returns the dict as a model

        :param dikt: A dict.
        :type: dict
        :return: The Customer of this Customer.  # noqa: E501
        :rtype: Customer
        """
        return util.deserialize_model(dikt, cls)

    @property
    def id(self) -> int:
        """Gets the id of this Customer.


        :return: The id of this Customer.
        :rtype: int
        """
        return self._id

    @id.setter
    def id(self, id: int):
        """Sets the id of this Customer.


        :param id: The id of this Customer.
        :type id: int
        """

        self._id = id

    @property
    def username(self) -> str:
        """Gets the username of this Customer.


        :return: The username of this Customer.
        :rtype: str
        """
        return self._username

    @username.setter
    def username(self, username: str):
        """Sets the username of this Customer.


        :param username: The username of this Customer.
        :type username: str
        """

        self._username = username

    @property
    def address(self) -> List[Address]:
        """Gets the address of this Customer.


        :return: The address of this Customer.
        :rtype: List[Address]
        """
        return self._address

    @address.setter
    def address(self, address: List[Address]):
        """Sets the address of this Customer.


        :param address: The address of this Customer.
        :type address: List[Address]
        """

        self._address = address