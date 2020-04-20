module.exports = {
    rules: {
        'body-leading-blank': [2, 'always'],
        'body-max-line-length': [2, 'always', 72],
        'footer-leading-blank': [2, 'always'],
        'footer-max-line-length': [2, 'always', 72],
        'header-max-length': [2, 'always', 50],
        'scope-case': [2, 'always', 'lower-case'],
        'subject-case': [
            2,
            'always',
            ['sentence-case']
        ],
        'subject-empty': [2, 'never'],
        'subject-full-stop': [2, 'never', '.'],
        'type-case': [2, 'always', 'lower-case'],
        'type-empty': [2, 'never'],
        'type-enum': [
            2,
            'always',
            [
                'fix',
                'feat',
                'chore',
                'docs',
                'style',
                'refactor',
                'perf',
                'test',
                'improv',
                'build',
                'ci',
                'revert',
            ]
        ],
        'signed-off-by': [2, 'always', 'Signed-off-by:']
    }
};
