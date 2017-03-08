const
    assert  = require('assert'),
    numname = require('bindings')('numname')

describe('numname', () => {
    describe('getName', () => {
        it('should fail with wrong number of arguments', () => {
            assert.throws(
                () => numname.getName(),
                /Gimme exactly one numeric argument/
            )
        })

        it('should fail with wrong argument', () => {
            assert.throws(
                () => numname.getName('1'),
                /Gimme exactly one numeric argument/
            )
        })

        it('should fail with negative', () => {
            assert.equal(numname.getName(-123), 'error')
        })

        it('should work with singles', () => {
            assert.equal(numname.getName(3), 'three')
        })

        it('should work with teens', () => {
            assert.equal(numname.getName(13), 'thirteen')
        })

        it('should work with tens', () => {
            assert.equal(numname.getName(47), 'forty-seven')
        })

        it('should work with just tens', () => {
            assert.equal(numname.getName(40), 'forty')
        })
        
        it('should work with hundreds', () => {
            assert.equal(numname.getName(492), 'four hundred ninety-two')
        })

        it('should work with thousands', () => {
            assert.equal(numname.getName(10012), 'ten thousand twelve')
        })

        it('should work with millions', () => {
            assert.equal(numname.getName(1000001), 'one million one')
        })

        it('should work with billions', () => {
            assert.equal(numname.getName(474142398123), 'four hundred seventy-four billion one hundred forty-two million three hundred ninety-eight thousand one hundred twenty-three')
        })
    })
})
