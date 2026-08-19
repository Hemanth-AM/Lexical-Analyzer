pipeline {
    agent any

    stages {

        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Build') {
            steps {
                sh '''
                    cd LexicalAnalyzer_my
                    gcc main.c lexical.c source.c -o lexical_analyzer
                '''
            }
        }

        stage('Test') {
            steps {
                sh '''
                    cd LexicalAnalyzer_my
                    ./lexical_analyzer
                '''
            }
        }
    }
}
