# coding: utf-8

from __future__ import absolute_import

from flask import json
from six import BytesIO

from swagger_server.models.number import Number  # noqa: E501
from swagger_server.models.pair import Pair  # noqa: E501
from swagger_server.test import BaseTestCase


class TestPairController(BaseTestCase):
    """PairController integration test stubs"""

    def test_add_nums(self):
        """Test case for add_nums

        add two numbers from pair
        """
        body = Pair()
        response = self.client.open(
            '/pair/add',
            method='POST',
            data=json.dumps(body),
            content_type='application/json')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_div_nums(self):
        """Test case for div_nums

        divide two numbers from pair
        """
        body = Pair()
        response = self.client.open(
            '/pair/divide',
            method='POST',
            data=json.dumps(body),
            content_type='application/json')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_multi_nums(self):
        """Test case for multi_nums

        multiply two numbers from pair
        """
        body = Pair()
        response = self.client.open(
            '/pair/multiply',
            method='POST',
            data=json.dumps(body),
            content_type='application/json')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_sub_nums(self):
        """Test case for sub_nums

        subtract two numbers from pair
        """
        body = Pair()
        response = self.client.open(
            '/pair/subtract',
            method='POST',
            data=json.dumps(body),
            content_type='application/json')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))


if __name__ == '__main__':
    import unittest
    unittest.main()
